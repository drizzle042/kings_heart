#ifndef __HttpOutput_T__
#define __HttpOutput_T__


namespace KingsHeart
{
    template<typename T>
    HttpOutput<T>::HttpOutput(const T& payload, HTTP_OUTPUT outputFormat)
    : HttpOutput<T>{
        payload, outputFormat,
        FileRegistry::get_file(get_env_t().DEFAULT_RESPONSE_TEMPLATE)
      }
    {}

    template<typename T>
    HttpOutput<T>::HttpOutput(const T& payload, HTTP_OUTPUT outputFormat, const File& file)
    {
        switch (outputFormat)
        {
        case HTTP_OUTPUT::CBOR:
            this->__outputFormat = std::make_shared<CborHttpOutput<T>>(payload);
            break;
        case HTTP_OUTPUT::JSON:
            this->__outputFormat = std::make_shared<JsonHttpOutput<T>>(payload);
            break;
        case HTTP_OUTPUT::HTML:
            this->__outputFormat = std::make_shared<HtmlHttpOutput<T>>(payload, file); 
            break;
        }
    }

    template<typename T>
    HttpResponse& HttpOutput<T>::operator()()
    { return (*this->__outputFormat)(); }
}

#endif