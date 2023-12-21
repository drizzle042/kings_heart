#include "ResetPassword.hpp"


namespace KingsHeart
{
    ResetPasswordCommand::ResetPasswordCommand(const AdminPassword_Input& input)
    : __input{&input} {}

    const Generic_Output& ResetPasswordCommand::operator()()
    {
        this->__output = Generic_Output{"success", "Password changed successfully."};
        return this->__output;
    }
}