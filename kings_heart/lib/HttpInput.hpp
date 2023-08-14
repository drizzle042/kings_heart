#pragma once

#include <string>
#include <string_view>
#include <unordered_set>
#include <drogon/HttpRequest.h>
#include <jsoncpp/json/value.h>
#include "Input.hpp"
#include "Payload.hpp"


namespace KingsHeart
{
    class HttpInput : public Input
    {
    private:
        drogon::HttpRequestPtr _requestPtr;
        std::shared_ptr<Payload> _payload;
        std::unordered_set<std::string> _requiredHeaderKeys;
        std::unordered_set<std::string> _requiredMsgKeys;
    public:
        HttpInput(drogon::HttpRequestPtr);
        ~HttpInput() =default;

        void add_required_header_key(std::string&&);
        void add_required_header_keys(std::unordered_set<std::string>&&);

        void add_required_message_key(std::string&&);
        void add_required_message_keys(std::unordered_set<std::string>&&);

        std::shared_ptr<Payload> get_input() override;
    };
}