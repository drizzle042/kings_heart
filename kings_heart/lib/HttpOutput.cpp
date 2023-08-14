#include "HttpOutput.hpp"
#include "Log.hpp"

namespace KingsHeart
{
    HttpOutput::HttpOutput(const Payload& payload)
    : _payload(payload){}

    drogon::HttpResponsePtr HttpOutput::get_output()
    {
        if (this->_httpResponsePtr == nullptr)
        {
            this->_httpResponsePtr = drogon::HttpResponse::newHttpResponse();
            for (const auto header : this->_payload.get_headers())
            {
                this->_httpResponsePtr->addHeader(header->get_key(), header->get_value());
            }

            Json::Value json;
            for (const auto msg : this->_payload.get_messages())
            {
                json[msg->get_key()] = msg->get_value();
            }

            this->_httpResponsePtr->setContentTypeCode(drogon::ContentType::CT_APPLICATION_JSON);
            Json::FastWriter fastWriter;
            this->_httpResponsePtr->setBody(fastWriter.write(json));
        }
        return this->_httpResponsePtr;
    }
}