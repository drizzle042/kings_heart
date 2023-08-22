#pragma once

#include <vector>
#include <string>
#include <unordered_set>
#include <utility>
#include <stdexcept>
#include "MetaDatum.hpp"
#include "Message.hpp"
#include "Payload.hpp"


namespace KingsHeart
{
    class PayloadBuilder
    {
    private:
        Payload _payload;
        
    public:
        PayloadBuilder& add_meta_datum(MetaDatum&&);
        PayloadBuilder& add_meta_data(std::vector<MetaDatum>&&);

        PayloadBuilder& add_required_meta_datum_key(std::string&&);
        PayloadBuilder& add_required_meta_datum_keys(std::unordered_set<std::string>&&);

        PayloadBuilder& add_message(Message&&);
        PayloadBuilder& add_messages(std::vector<Message>&&);

        PayloadBuilder& add_required_message_key(std::string&&);
        PayloadBuilder& add_required_message_keys(std::unordered_set<std::string>&&);

        const Payload build() const;
    };
}