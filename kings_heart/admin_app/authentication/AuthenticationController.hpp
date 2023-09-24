#ifndef AuthenticationController_H
#define AuthenticationController_H

#include <memory>
#include <bsoncxx/json.hpp>
#include "Command.hpp"
#include "Bagit.hpp"
#include "JsonWebToken.hpp"
#include "DatabaseRegistry.hpp"


namespace KingsHeart
{
    class SigninCommand : public Command
    {
    private:
        std::shared_ptr<Payload> _payload;
    
    public:
        SigninCommand(const Payload&);
        Payload execute() override;
    };
}

#endif