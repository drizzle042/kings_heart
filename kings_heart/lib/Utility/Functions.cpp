#include "Functions.hpp"


namespace KingsHeart
{
    std::string get_env_var(const std::string& var, bool required) noexcept(false)
    {
        char* env_name = std::getenv(var.c_str());

        if (!env_name && required)
        { throw std::runtime_error("No environment variable matches the name " + var); }

        return env_name ? std::string(env_name) : "";
    }

    inja::Environment env_factory()
    {
        inja::Environment env;
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