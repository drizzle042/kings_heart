#include "JsonHttpOutput.hpp"


namespace KingsHeart
{
    JsonHttpOutput::JsonHttpOutput(const Payload& payload)
    : _payload(payload){}

    drogon::HttpResponsePtr JsonHttpOutput::get_output()
    {
        if (this->_httpResponsePtr == nullptr)
        {
            Json::Value json;
            for (const auto msg : this->_payload.get_messages())
            {
                json[msg->get_key()] = msg->get_value();
            }
            this->_httpResponsePtr = drogon::HttpResponse::newHttpJsonResponse(json);

            for (const auto metaDatum : this->_payload.get_meta_data())
            {
                this->_httpResponsePtr->addHeader(metaDatum->get_key(), metaDatum->get_value());
            }
        }
        return this->_httpResponsePtr;
    }
}