#ifndef HtmlHttpOutput_T
#define HtmlHttpOutput_T


namespace KingsHeart
{
    template<typename T>
    HtmlHttpOutput<T>::HtmlHttpOutput(const T& payload, const File& file)
    : __payload{&payload},
      __file{&file} {}
    
    template<typename T>
    inja::Environment HtmlHttpOutput<T>::__INJA = env_factory();

    template<typename T>
    HttpResponse& HtmlHttpOutput<T>::operator()()
    {
        if (this->__httpResponse == nullptr)
        {
            inja::json output;
            output["global"] = *this->__payload;

            this->__httpResponse = drogon::HttpResponse::newHttpResponse();
            this->__httpResponse->addHeader("Content-Type", "text/html");            
            this->__httpResponse->setBody(HtmlHttpOutput<T>::__INJA.render(std::string(*this->__file), output));
        }
        return this->__httpResponse;
    }
}

#endif