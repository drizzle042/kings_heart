#ifndef __GenerateAdminAuth_C_H__
#define __GenerateAdminAuth_C_H__

#include <string>
#include "Command.hpp"
#include "AdminBagit.hpp"
#include "JsonWebToken.hpp"
#include "Password.hpp"
#include "GetAdmin.hpp"
#include "Unauthorized.hpp"


namespace KingsHeart
{
    class GenerateAdminTokenCommand : public Command<AdminAuth_Output>
    {
    public:
        explicit GenerateAdminTokenCommand(const AdminAuth_Input&);
        const AdminAuth_Output& operator()() override;

    private:
        const AdminAuth_Input* __input;
        AdminAuth_Output __output;
    };
}

#endif