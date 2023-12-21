#include "GenerateAdminToken.hpp"


namespace KingsHeart
{
    GenerateAdminTokenCommand::GenerateAdminTokenCommand(const AdminAuth_Input& input)
    : __input{&input} {}

    const AdminAuth_Output& GenerateAdminTokenCommand::operator()()
    {
        nlohmann::json query = {{"contact_email", this->__input->email}};
        GetAdminCommand<AdminAuth_DatabasePayload> GetAdmin{query};
        const AdminAuth_DatabasePayload& payload = GetAdmin();

        JsonWebToken token{{{"id", payload.admin_id}}};

        if (Password{payload.password} == this->__input->password)
        {
            this->__output = AdminAuth_Output{"success", std::string(token)};
            return this->__output;
        }
        
        throw Unauthorized{"Could not authenticate."};
    }
}