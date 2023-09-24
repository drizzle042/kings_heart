#include "JsonHttpOutput.hpp"


namespace KingsHeart
{
    JsonHttpOutput::JsonHttpOutput(const Payload& payload)
    : _payload{std::shared_ptr<Payload>{const_cast<Payload*>(&payload)}} {}

    HttpResponse& JsonHttpOutput::get_output()
    {
        if (this->_httpResponse == nullptr)
        {
            Json::Value json;
            for (const auto& msg : this->_payload->get_messages())
            { json[msg.first] = msg.second.read(); }

            this->_httpResponse = drogon::HttpResponse::newHttpJsonResponse(json);

            for (const auto& metaDatum : this->_payload->get_meta_data())
            { this->_httpResponse->addHeader(metaDatum.first, metaDatum.second.read()); }
        }
        return this->_httpResponse;
    }
}