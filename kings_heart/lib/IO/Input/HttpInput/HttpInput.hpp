#pragma once

#include <string>
#include <string_view>
#include <unordered_set>
#include <drogon/HttpRequest.h>
#include <jsoncpp/json/value.h>
#include "Input.hpp"
#include "Payload.hpp"
#include "PayloadBuilder.hpp"


namespace KingsHeart
{
    class HttpInput : public Input
    {
    private:
        drogon::HttpRequestPtr _requestPtr;
        PayloadBuilder _payloadBuilder;
        std::shared_ptr<Payload> _payload;
        std::unordered_set<std::string> _requiredMetaDatumKeys;
        std::unordered_set<std::string> _requiredMsgKeys;
        
    public:
        HttpInput(drogon::HttpRequestPtr);
        ~HttpInput() =default;

        HttpInput& add_required_meta_datum_key(std::string&&);
        HttpInput& add_required_meta_datum_keys(std::unordered_set<std::string>&&);

        HttpInput& add_required_message_key(std::string&&);
        HttpInput& add_required_message_keys(std::unordered_set<std::string>&&);

        Payload get_input() override;
    };
}