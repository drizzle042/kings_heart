#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <utility>
#include <stdexcept>
#include "Header.hpp"
#include "Message.hpp"


namespace KingsHeart
{
    class PayloadBuilder;

    class Payload
    {
    private:
        Payload() =default;

        std::unordered_map<std::string, Header> _headers;
        std::unordered_set<std::string> _requiredHeaderKeys;

        std::unordered_map<std::string, Message> _messages;
        std::unordered_set<std::string> _requiredMessageKeys;

    public:
        friend class PayloadBuilder;
        ~Payload() =default;
        
        const Header* find_header_by_key(const std::string&) const;
        const Header* find_header_by_value(const std::string&) const;
        const std::unordered_set<const Header*> get_headers() const;

        const Message* find_message_by_key(const std::string&) const;
        const Message* find_message_by_value(const std::string&) const;
        const std::unordered_set<const Message*> get_messages() const;
    };

    class PayloadBuilder
    {
    private:
        Payload _payload;
    public:
        PayloadBuilder() =default;
        ~PayloadBuilder() =default;
        
        PayloadBuilder& add_header(Header&&);
        PayloadBuilder& add_headers(std::vector<Header>&&);

        PayloadBuilder& add_required_header_key(std::string&&);
        PayloadBuilder& add_required_header_keys(std::unordered_set<std::string>&&);

        PayloadBuilder& add_message(Message&&);
        PayloadBuilder& add_messages(std::vector<Message>&&);

        PayloadBuilder& add_required_message_key(std::string&&);
        PayloadBuilder& add_required_message_keys(std::unordered_set<std::string>&&);

        const Payload build() const;
    };
}