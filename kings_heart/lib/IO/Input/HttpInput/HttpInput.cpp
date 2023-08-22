#include "HttpInput.hpp"

namespace KingsHeart
{
    HttpInput::HttpInput(drogon::HttpRequestPtr requestPtr)
    : _requestPtr{requestPtr} {}


    HttpInput& HttpInput::add_required_meta_datum_key(std::string&& requiredMetaDatumKey)
    { 
        this->_payloadBuilder.add_required_meta_datum_key(std::move(requiredMetaDatumKey));
        return *this;
    }

    HttpInput& HttpInput::add_required_meta_datum_keys(std::unordered_set<std::string>&& requiredMetaDatumKeys)
    { 
        this->_payloadBuilder.add_required_meta_datum_keys(std::move(requiredMetaDatumKeys));
        return *this;
    }


    HttpInput& HttpInput::add_required_message_key(std::string&& requiredMsgKey)
    { 
        this->_payloadBuilder.add_required_message_key(std::move(requiredMsgKey));
        return *this;
    }

    HttpInput& HttpInput::add_required_message_keys(std::unordered_set<std::string>&& requiredMsgKeys)
    { 
        this->_payloadBuilder.add_required_message_keys(std::move(requiredMsgKeys));
        return *this;
    }


    Payload HttpInput::get_input()
    {
        if (this->_payload == nullptr)
        {
            auto requestMetaData = _requestPtr->getHeaders();
            for (const auto requestMetaDatum : requestMetaData)
            {
                this->_payloadBuilder.add_meta_datum(MetaDatum(requestMetaDatum.first, requestMetaDatum.second));
            }

            auto requestParams = _requestPtr->getParameters();
            for (const auto requestParam : requestParams)
            {
                this->_payloadBuilder.add_message(Message(requestParam.first, requestParam.second));
            }

            const std::string contentType = _requestPtr->getHeader("Content-Type");

            if (contentType == "application/json")
            {
                const std::shared_ptr<Json::Value> requestJson = _requestPtr->getJsonObject();
                for (const auto& key : requestJson->getMemberNames())
                { this->_payloadBuilder.add_message(Message(key, (*requestJson)[key].asString())); }
            }

            if (
                (contentType == "application/xml") || 
                (contentType == "text/csv") || 
                (contentType == "text/html") ||
                (contentType == "text/xml") ||
                (contentType == "text/plain") 
            )
            {
                const std::string_view requestBody = _requestPtr->getBody();
                this->_payloadBuilder.add_message(Message("message", std::string(requestBody)));
            }

            this->_payload = std::make_shared<Payload>(this->_payloadBuilder.build());
        }
        return *this->_payload;
    }
}