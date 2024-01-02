#include "Functions.hpp"


namespace KingsHeart
{
    std::string get_env_var(const std::string& var, bool required = true) noexcept(false)
    {
        char* env_name = std::getenv(var.c_str());

        if (!env_name && required)
        { throw std::runtime_error("No environment variable matches the name " + var); }

        return env_name ? std::string(env_name) : "";
    }

    inja::Environment& env_factory()
    {
        static inja::Environment env;
        static int once = []() -> int {
            env.add_callback(
                    "indent", 1, 
                    [](inja::Arguments& args)
                    {
                        const inja::json* input = args[0];
                        uint8_t INDENT_LEVEL = 4;
                        return input->dump(INDENT_LEVEL);
                    }
                );
            env.add_callback(
                    "indent", 2, 
                    [](inja::Arguments& args)
                    {
                        const inja::json* input = args[0];
                        uint8_t INDENT_LEVEL = args[1]->get<uint8_t>();
                        return input->dump(INDENT_LEVEL);
                    }
                );
            return 0;
        }();

        return env;
    }

    std::vector<std::string> split(const std::string& input, const std::string& delimiter)
    {
        std::string s = input;
        std::vector<std::string> output;

        size_t pos = 0;
        while ((pos = s.find(delimiter)) != std::string::npos) 
        {
            output.push_back(s.substr(0, pos));
            s.erase(0, pos + delimiter.size());
        }
        output.push_back(s);

        return output;
    }

    std::string generate_salt()
    {
        static std::random_device randomDevice;
        static std::uniform_int_distribution<unsigned int> distribution{1000, 4294967290};

        unsigned int SALT = distribution(randomDevice);
        std::stringstream stream;
        stream << std::hex << SALT;
        std::string salt = stream.str();
        std::transform(salt.begin(), salt.end(), salt.begin(), [](unsigned char c) { return std::toupper(c); });

        return salt;
    }
}

namespace KingsHeart
{
    const environment_t& get_env_t()
    {
        static environment_t values = {
            get_env_var("Kings_Heart_Main_Logger"),
            get_env_var("Kings_Heart_Command_Storage_Logger"),
            get_env_var("Kings_Heart_Command_Storage_Logger_Path"),
            get_env_var("Kings_Heart_Command_Storage_Logger_Max_File_Size"),
            get_env_var("Kings_Heart_Command_Storage_Logger_Max_Allowed_Files"),
            get_env_var("Kings_Heart_Main_Database_Server_URI"),
            get_env_var("Kings_Heart_Main_Database"),
            get_env_var("Kings_Heart_Main_Database_Admin_Table"),
            get_env_var("Kings_Heart_JWT_Secret_Key"),
            get_env_var("Kings_Heart_JWT_Algorithm"),
            get_env_var("Kings_Heart_Password_Secret_Key"),
            get_env_var("Kings_Heart_Password_Algorithm", false),
            get_env_var("Kings_Heart_Server_Email"),
            get_env_var("Kings_Heart_Brevo_Email_API"),
            get_env_var("Kings_Heart_Brevo_Email_API_Key"),
            get_env_var("Kings_Heart_Default_Response_Template"),
            get_env_var("Kings_Heart_OTP_Email_Template")
        };
        return values;
    };
}