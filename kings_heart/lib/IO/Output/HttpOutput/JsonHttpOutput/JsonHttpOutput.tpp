#ifndef __JsonHttpOutput_T__
#define __JsonHttpOutput_T__


namespace KingsHeart
{
    template<typename T>
    JsonHttpOutput<T>::JsonHttpOutput(const T& payload)
    : _payload{&payload} {}

    template<typename T>
    HttpResponse& JsonHttpOutput<T>::operator()()
    {
        if (this->_httpResponse == nullptr)
        {
            nlohmann::json output = *this->_payload;

            this->_httpResponse = drogon::HttpResponse::newHttpResponse();
            this->_httpResponse->addHeader("Content-Type", "application/json");
            this->_httpResponse->setBody(output.dump());
        }
        return this->_httpResponse;
    }
}

#endif