#include "RequestAdminOTP.hpp"
#include <iostream>


namespace KingsHeart
{
    extern std::string OTP_EMAIL_TEMPLATE;

    void notify(drogon::ReqResult, const drogon::HttpResponsePtr& res)
    { std::cout << res->getBody(); };

    void RequestAdminOTP::send_OTP(
        const drogon::HttpRequestPtr& request, 
        drogon::AdviceCallback&& responder
    ) const
    {
        HttpInput<AdminOTPRequest_Input> Input{request};
        const AdminOTPRequest_Input& input = Input();

        GenerateOTPCommand GenOTP{input};
        const AdminOTP_Output& output = GenOTP();

        static inja::Environment INJA  = env_factory();
        
        if (input.email)
        {
            nlohmann::json variables = {
                {"name", output.admin.first_name},
                {"OTP", output.OTP}
            };

            std::vector<EmailContact> receipients{{output.admin.first_name, output.admin.contact_email}};
            std::string subject{"OTP Request"};
            const std::string& fileContent = FileRegistry::get_file(get_env_var(OTP_EMAIL_TEMPLATE));
            std::string message = INJA.render(fileContent, variables);

            EmailMessenger Messenger{std::move(receipients), std::move(subject), std::move(message), &notify};
            Messenger();

            HttpOutput<Generic_Output> Output{Generic_Output{"success", "Email sent."}, Input.get_output_type()};

            responder(Output());
            return;
        }

        throw BadRequest{"One of email or sms is required."};
    }
}