#include "HttpInput.hpp"

namespace KingsHeart
{
    HttpInput::HttpInput(HttpRequest request)
    : _request{request} {}

    HttpInput& HttpInput::add_required_meta_datum_keys(const std::vector<std::string>& requiredMetaDatumKeys)
    { 
        this->_payloadBuilder.add_required_meta_data(requiredMetaDatumKeys);
        return *this;
    }

    HttpInput& HttpInput::add_required_message_keys(const std::vector<std::string>& requiredMsgKeys)
    { 
        this->_payloadBuilder.add_required_messages(requiredMsgKeys);
        return *this;
    }


    const Payload& HttpInput::get_input()
    {
        if (!this->_payload)
        {
            for (const auto& requestMetaDatum : this->_request->getHeaders())
            { this->_payloadBuilder.add_meta_datum(requestMetaDatum.first, MetaDatum{requestMetaDatum.second}); }

            for (const auto& requestParam : this->_request->getParameters())
            { this->_payloadBuilder.add_meta_datum(requestParam.first, MetaDatum{requestParam.second}); }

            drogon::ContentType _c = this->_request->getContentType();
            std::shared_ptr<Json::Value> requestJson;
            std::string_view requestBody;

            switch(_c)
            {
            case drogon::ContentType::CT_APPLICATION_JSON:

                requestJson = this->_request->getJsonObject();
                for (const auto& key : requestJson->getMemberNames())
                { this->_payloadBuilder.add_message(key, Message{(*requestJson)[key].asString()}); }

                break;

            case drogon::ContentType::CT_APPLICATION_XML:
            case drogon::ContentType::CT_TEXT_XML:
            case drogon::ContentType::CT_TEXT_HTML:
            case drogon::ContentType::CT_TEXT_PLAIN:

                requestBody = this->_request->getBody();
                this->_payloadBuilder.add_message("message", Message{std::string(requestBody)});

                break;

            default:
                break;
            }

            this->_payload = std::make_shared<Payload>(this->_payloadBuilder.build());
        }
        return *this->_payload;
    }
}