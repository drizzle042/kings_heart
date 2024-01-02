#ifndef __HtmlHttpOutput_T__
#define __HtmlHttpOutput_T__


namespace KingsHeart
{
    template<typename T>
    HtmlHttpOutput<T>::HtmlHttpOutput(const T& payload, const File& file)
    : __payload{&payload},
      __file{&file} {}

    template<typename T>
    HttpResponse& HtmlHttpOutput<T>::operator()()
    {
        if (this->__httpResponse == nullptr)
        {
            inja::json output = {{"global", *this->__payload}};

            this->__httpResponse = drogon::HttpResponse::newHttpResponse();
            this->__httpResponse->addHeader("Content-Type", "text/html");            
            this->__httpResponse->setBody(env_factory().render(std::string(*this->__file), output));
        }
        return this->__httpResponse;
    }
}

#endif