#pragma once

#include <memory>
#include "Command.hpp"
#include "Payload.hpp"
#include "PayloadBuilder.hpp"
#include "JsonWebToken.hpp"

namespace KingsHeart
{
    class SigninCommand : public Command
    {
    private:
        Payload _payload;
    
    public:
        SigninCommand(const Payload&);
        Payload execute() override;
    };
}