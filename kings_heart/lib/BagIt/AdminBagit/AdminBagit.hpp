#ifndef __AdminBagit_H__
#define __AdminBagit_H__

#include <string>
#include <nlohmann/json.hpp>


namespace KingsHeart
{
    struct AdminAuth_Input
    {
        std::string email;
        std::string password;
    };

    void to_json(nlohmann::json&, const AdminAuth_Input&);
    void from_json(const nlohmann::json&, AdminAuth_Input&);
}

namespace KingsHeart
{
    struct AdminPassword_Input
    {
        std::string password;
    };

    void to_json(nlohmann::json&, const AdminPassword_Input&);
    void from_json(const nlohmann::json&, AdminPassword_Input&);
}

namespace KingsHeart
{
    struct AdminOTPRequest_Input
    {
        std::string admin_id;
        bool email;
        bool mobile;
    };

    void to_json(nlohmann::json&, const AdminOTPRequest_Input&);
    void from_json(const nlohmann::json&, AdminOTPRequest_Input&);
}

namespace KingsHeart
{
    struct AdminBrief_DatabasePayload
    {
        uint32_t _id;
        std::string admin_id;
        std::string first_name;
        std::string last_name;
        std::string display_name;
        std::string contact_email;
        std::string contact_phone;
        bool is_super_admin;
        bool is_main_admin;
        bool is_cbt_admin;
        bool is_authenticated;
    };

    void to_json(nlohmann::json&, const AdminBrief_DatabasePayload&);
    void from_json(const nlohmann::json&, AdminBrief_DatabasePayload&);
}

namespace KingsHeart
{
    struct AdminOTP_Output
    {
        unsigned short OTP;
        AdminBrief_DatabasePayload admin;
    };

    void to_json(nlohmann::json&, const AdminOTP_Output&);
    void from_json(const nlohmann::json&, AdminOTP_Output&);
}

namespace KingsHeart
{
    struct AdminAuth_DatabasePayload
    {
        std::string admin_id;
        std::string password;
    };

    void to_json(nlohmann::json&, const AdminAuth_DatabasePayload&);
    void from_json(const nlohmann::json&, AdminAuth_DatabasePayload&);
}

namespace KingsHeart
{
    struct AdminAuth_Output
    {
        std::string status;
        std::string token;
    };

    void to_json(nlohmann::json&, const AdminAuth_Output&);
    void from_json(const nlohmann::json&, AdminAuth_Output&);
}

#endif