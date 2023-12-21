#ifndef __CborHttpOutput_T__
#define __CborHttpOutput_T__

#include <iostream>

namespace KingsHeart
{
    template<typename T>
    CborHttpOutput<T>::CborHttpOutput(const T& payload)
    : _payload{&payload} {}

    template<typename T>
    HttpResponse& CborHttpOutput<T>::operator()()
    {
        if (this->_httpResponse == nullptr)
        {
            nlohmann::json output = *this->_payload;
            std::vector<std::uint8_t> cbor{nlohmann::json::to_cbor(output)};

            this->_httpResponse = drogon::HttpResponse::newHttpResponse();
            this->_httpResponse->addHeader("Content-Type", "application/cbor");
            this->_httpResponse->setBody({reinterpret_cast<const char*>(cbor.data()), cbor.size()});
        }
        return this->_httpResponse;
    }
}

#endif