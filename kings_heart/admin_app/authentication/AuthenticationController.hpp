#pragma once

#include <memory>
#include "Command.hpp"
#include "Payload.hpp"
#include "Tokenizer.hpp"

namespace KingsHeart
{
    class SigninCommand : public Command
    {
    private:
        std::shared_ptr<Payload> _payload;
    
    public:
        SigninCommand(std::shared_ptr<Payload>);
        ~SigninCommand() =default;
        Payload execute() override;
    };
}