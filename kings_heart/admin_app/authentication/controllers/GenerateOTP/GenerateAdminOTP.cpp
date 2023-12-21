#include "GenerateAdminOTP.hpp"


namespace KingsHeart
{
    GenerateOTPCommand::GenerateOTPCommand(const AdminOTPRequest_Input& input)
    : __input{&input} {}

    const AdminOTP_Output& GenerateOTPCommand::operator()()
    {
        if (this->__input->admin_id.empty()) throw BadRequest{"admin_id is required."};

        nlohmann::json query = {{"admin_id", this->__input->admin_id}};
        GetAdminCommand<AdminBrief_DatabasePayload> GetAdmin{query};
        const AdminBrief_DatabasePayload& admin = GetAdmin();

        static std::random_device randomDevice;
        static std::uniform_int_distribution<unsigned short int> distribution{1, 65000};

        unsigned short int OTP = distribution(randomDevice);

        this->__output = AdminOTP_Output{OTP, admin};

        return this->__output;
    }
            
}