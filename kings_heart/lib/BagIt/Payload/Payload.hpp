#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include "MetaDatum.hpp"
#include "Message.hpp"


namespace KingsHeart
{
    class PayloadBuilder;

    class Payload
    {
    private:
        Payload() =default;

        std::unordered_map<std::string, MetaDatum> _metaData;
        std::unordered_set<std::string> _requiredMetaDatumKeys;

        std::unordered_map<std::string, Message> _messages;
        std::unordered_set<std::string> _requiredMessageKeys;

    public:
        friend class PayloadBuilder;
        
        const MetaDatum* get_meta_datum_by_key(const std::string&) const;
        const MetaDatum* get_meta_datum_by_value(const std::string&) const;
        const std::unordered_set<const MetaDatum*> get_meta_data() const;
        const std::unordered_set<std::string> get_required_meta_datum_keys() const;

        const Message* get_message_by_key(const std::string&) const;
        const Message* get_message_by_value(const std::string&) const;
        const std::unordered_set<const Message*> get_messages() const;
        const std::unordered_set<std::string> get_required_message_keys() const;
    };
}