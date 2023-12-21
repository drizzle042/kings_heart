#ifndef __ResetPassword_H__
#define __ResetPassword_H__

#include "Command.hpp"
#include "AdminBagit.hpp"
#include "GenericBagit.hpp"

namespace KingsHeart
{
    class ResetPasswordCommand : public Command<Generic_Output>
    {
    public:
        explicit ResetPasswordCommand(const AdminPassword_Input&);
        const Generic_Output& operator()() override;

    private:
        const AdminPassword_Input* __input;
        Generic_Output __output;
    };
}

#endif