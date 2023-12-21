#ifndef __GenerateOTP_H__
#define __GenerateOTP_H__

#include <random>
#include "Functions.hpp"
#include "Command.hpp"
#include "AdminBagit.hpp"
#include "GetAdmin.hpp"
#include "EmailMessenger.hpp"
#include "EmailContactBagit.hpp"
#include "FileRegistry.hpp"
#include "BadRequest.hpp"


namespace KingsHeart
{
    class GenerateOTPCommand : public Command<AdminOTP_Output>
    {
    public:
        explicit GenerateOTPCommand(const AdminOTPRequest_Input&);
        const AdminOTP_Output& operator()() override;

    private:
        const AdminOTPRequest_Input* __input;
        AdminOTP_Output __output;
    };
}

#endif