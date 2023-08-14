#include "AuthenticationController.hpp"

namespace KingsHeart
{
    SigninCommand::SigninCommand(std::shared_ptr<Payload> payload)
    : _payload{payload}{}

    Payload SigninCommand::execute()
    {
        const Message* email = this->_payload->find_message_by_key("email");
        const Message* password = this->_payload->find_message_by_key("password");

        Token token{std::unordered_map<std::string, std::string>{
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