#include "AdminBagit.hpp"


namespace KingsHeart
{
    void to_json(nlohmann::json& output, const AdminAuth_Input& input)
    { output = nlohmann::json{ {"email", input.email}, {"password", input.password} }; }

    void from_json(const nlohmann::json& input, AdminAuth_Input& output)
    {
        auto email = input.find("email");
        output.email = (email != input.end() && !(email->is_null())) ? *email : "";

        auto password = input.find("password");
        output.password = (password != input.end() && !(password->is_null())) ? *password : "";
    }
}

namespace KingsHeart
{
    void to_json(nlohmann::json& output, const AdminPassword_Input& input)
    { output = nlohmann::json{ {"password", input.password} }; }

    void from_json(const nlohmann::json& input, AdminPassword_Input& output)
    {
        auto password = input.find("password");
        output.password = (password != input.end() && !(password->is_null())) ? *password : "";
    }
}

namespace KingsHeart
{
    void to_json(nlohmann::json& output, const AdminOTP_Output& input)
    { output = nlohmann::json{ {"OTP", input.OTP}, {"admin", input.admin} }; }

    void from_json(const nlohmann::json& input, AdminOTP_Output& output)
    {
        auto OTP = input.find("OTP");
        if (OTP != input.end() && !(OTP->is_null())) output.OTP = *OTP;
        else output.OTP = 0;

        auto admin = input.find("admin");
        if (admin != input.end() && !(admin->is_null())) output.admin = *admin;
    }
}

namespace KingsHeart
{
    void to_json(nlohmann::json& output, const AdminOTPRequest_Input& input)
    { 
        output = nlohmann::json{ 
            {"admin_id", input.admin_id},
            {"email", input.email}, 
            {"mobile", input.mobile}
        }; 
    }

    void from_json(const nlohmann::json& input, AdminOTPRequest_Input& output)
    {
        auto admin_id = input.find("admin_id");
        output.admin_id = (admin_id != input.end() && !(admin_id->is_null())) ? *admin_id : "";

        auto email = input.find("email");
        if (email != input.end() && !(email->is_null())) output.email = *email;
        else output.email = false;

        auto mobile = input.find("mobile");
        if (mobile != input.end() && !(mobile->is_null())) output.mobile = *mobile;
        else output.mobile = false;
    }
}

namespace KingsHeart
{
    void to_json(nlohmann::json& output, const AdminAuth_DatabasePayload& input)
    { output = nlohmann::json{ {"admin_id", input.admin_id}, {"password", input.password} }; }

    void from_json(const nlohmann::json& input, AdminAuth_DatabasePayload& output)
    {
        auto admin_id = input.find("admin_id");
        output.admin_id = (admin_id != input.end() && !(admin_id->is_null())) ? *admin_id : "";

        auto password = input.find("password");
        output.password = (password != input.end() && !(password->is_null())) ? *password : "";
    }
}

namespace KingsHeart
{
    void to_json(nlohmann::json& output, const AdminBrief_DatabasePayload& input)
    { 
        output = nlohmann::json{ 
                    {"_id", input._id}, 
                    {"admin_id", input.admin_id},
                    {"first_name", input.first_name},
                    {"last_name", input.last_name},
                    {"display_name", input.display_name},
                    {"contact_email", input.contact_email},
                    {"contact_phone", input.contact_phone},
                    {"is_super_admin", input.is_super_admin},
                    {"is_main_admin", input.is_main_admin},
                    {"is_cbt_admin", input.is_cbt_admin},
                    {"is_authenticated", input.is_authenticated}
                }; 
    }

    void from_json(const nlohmann::json& input, AdminBrief_DatabasePayload& output)
    {
        auto _id = input.find("_id");
        output._id = (_id != input.end() && !(_id->is_null())) ? *_id : "";

        auto admin_id = input.find("admin_id");
        output.admin_id = (admin_id != input.end() && !(admin_id->is_null())) ? *admin_id : "";

        auto first_name = input.find("first_name");
        output.first_name = (first_name != input.end() && !(first_name->is_null())) ? *first_name : "";

        auto last_name = input.find("last_name");
        output.last_name = (last_name != input.end() && !(last_name->is_null())) ? *last_name : "";

        auto display_name = input.find("display_name");
        output.display_name = (display_name != input.end() && !(display_name->is_null())) ? *display_name : "";

        auto contact_email = input.find("contact_email");
        output.contact_email = (contact_email != input.end() && !(contact_email->is_null())) ? *contact_email : "";

        auto contact_phone = input.find("contact_phone");
        output.contact_phone = (contact_phone != input.end() && !(contact_phone->is_null())) ? *contact_phone : "";

        auto is_super_admin = input.find("is_super_admin");
        output.is_super_admin = (is_super_admin != input.end() && !(is_super_admin->is_null())) ? *is_super_admin : "";

        auto is_main_admin = input.find("is_main_admin");
        output.is_main_admin = (is_main_admin != input.end() && !(is_main_admin->is_null())) ? *is_main_admin : "";

        auto is_cbt_admin = input.find("is_cbt_admin");
        output.is_cbt_admin = (is_cbt_admin != input.end() && !(is_cbt_admin->is_null())) ? *is_cbt_admin : "";

        auto is_authenticated = input.find("is_authenticated");
        output.is_authenticated = (is_authenticated != input.end() && !(is_authenticated->is_null())) ? *is_authenticated : "";
    }
}

namespace KingsHeart
{
    void to_json(nlohmann::json& output, const AdminAuth_Output& input)
    { 
        output = nlohmann::json{ 
                    {"status", input.status}, 
                    {"token", input.token}
                }; 
    }

    void from_json(const nlohmann::json& input, AdminAuth_Output& output)
    {
        auto status = input.find("status");
        output.status = (status != input.end() && !(status->is_null())) ? *status : "";

        auto token = input.find("token");
        output.token = (token != input.end() && !(token->is_null())) ? *token : "";
    }
}