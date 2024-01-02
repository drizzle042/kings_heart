#include "RequestAdminOTP.hpp"
#include "MainLog.hpp"


namespace KingsHeart
{
    struct Notify
    {
        void operator()(drogon::ReqResult, const drogon::HttpResponsePtr& res)
        { if(res) MainLog::info(std::string(res->getBody())); };
    };

    void RequestAdminOTP::send_OTP(
        const drogon::HttpRequestPtr& request, 
        drogon::AdviceCallback&& responder
    ) const
    {
        HttpInput<AdminOTPRequest_Input> Input{request};
        const AdminOTPRequest_Input& input = Input();

        GenerateOTPCommand GenOTP{input};
        const AdminOTP_Output& output = GenOTP();
        
        if (input.email)
        {
            nlohmann::json variables = {
                {"name", output.admin.first_name},
                {"OTP", output.OTP}
            };

            std::vector<EmailContact> receipients{{output.admin.first_name, output.admin.contact_email}};
            std::string subject{"OTP Request"};
            const std::string& fileContent = FileRegistry::get_file(get_env_t().OTP_EMAIL_TEMPLATE);
            std::string message = env_factory().render(fileContent, variables);

            EmailMessenger Messenger{std::move(receipients), std::move(subject), std::move(message), Notify()};
            Messenger();

            HttpOutput<Generic_Output> Output{Generic_Output{"success", "Email sent."}, Input.get_output_type()};

            responder(Output());
            return;
        }

        throw BadRequest{"One of email or sms is required."};
    }
}