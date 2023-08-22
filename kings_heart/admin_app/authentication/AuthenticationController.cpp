#include "AuthenticationController.hpp"

namespace KingsHeart
{
    SigninCommand::SigninCommand(const Payload& payload)
    : _payload{payload}{}

    Payload SigninCommand::execute()
    {
        const Message* email = this->_payload.get_message_by_key("email");
        const Message* password = this->_payload.get_message_by_key("password");

        JsonWebToken token{std::unordered_map<std::string, std::string>{
            {email->get_key(), email->get_value()},
            {password->get_key(), password->get_value()}
        }};

        PayloadBuilder payloadBuilder;
        payloadBuilder.add_messages({
            Message{"status", "success"},
            Message{"data", token.get_token()}
        });
        
        return payloadBuilder.build();
    }
}