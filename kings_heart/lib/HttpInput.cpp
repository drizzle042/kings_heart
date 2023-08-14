#include "HttpInput.hpp"

namespace KingsHeart
{
    HttpInput::HttpInput(drogon::HttpRequestPtr requestPtr)
    : _requestPtr{requestPtr} {}


    void HttpInput::add_required_header_key(std::string&& requiredHeaderKey)
    { this->_requiredHeaderKeys.insert(requiredHeaderKey); }

    void HttpInput::add_required_header_keys(std::unordered_set<std::string>&& requiredHeaderKeys)
    {
        for (const std::string& requiredHeaderKey : requiredHeaderKeys) {
            this->_requiredHeaderKeys.insert(requiredHeaderKey);
        }
    }


    void HttpInput::add_required_message_key(std::string&& requiredMsgKey)
    { this->_requiredMsgKeys.insert(requiredMsgKey); }

    void HttpInput::add_required_message_keys(std::unordered_set<std::string>&& requiredMsgKeys)
    {
        for (const std::string& requiredMsgKey : requiredMsgKeys) {
            this->_requiredMsgKeys.insert(requiredMsgKey);
        }
    }


    std::shared_ptr<Payload> HttpInput::get_input()
    {
        if (this->_payload == nullptr)
        {
            PayloadBuilder payloadBuilder;

            auto requestHeaders = _requestPtr->getHeaders();
            for (const auto requestHeader : requestHeaders)
            {
                payloadBuilder.add_header(Header(requestHeader.first, requestHeader.second));
            }

            auto requestParams = _requestPtr->getParameters();
            for (const auto requestParam : requestParams)
            {
                payloadBuilder.add_message(Message(requestParam.first, requestParam.second));
            }

            const std::shared_ptr<Json::Value> requestJson = _requestPtr->getJsonObject();
            if (requestJson)
            {
                for (const auto& key : requestJson->getMemberNames())
                {
                    payloadBuilder.add_message(Message(key, (*requestJson)[key].asString()));
                }
            }

            const std::string_view requestBody = _requestPtr->getBody();
            payloadBuilder.add_message(Message("message", std::string(requestBody)));

            this->_payload = std::make_shared<Payload>(payloadBuilder.build());
        }
        return this->_payload;
    }
}