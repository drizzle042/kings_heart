#ifndef __Functions_H__
#define __Functions_H__

#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <random>
#include <inja/inja.hpp>


namespace KingsHeart
{
    struct environment_t
    {
        std::string MAIN_LOGGER;
        std::string COMMAND_STORAGE_LOGGER;
        std::string COMMAND_STORAGE_LOGGER_PATH;
        std::string COMMAND_STORAGE_LOGGER_MAX_FILE_SIZE;
        std::string COMMAND_STORAGE_LOGGER_MAX_ALLOWED_FILES;
        std::string MAIN_DATABASE_SERVER_URI;
        std::string MAIN_DATABASE;
        std::string MAIN_DATABASE_ADMIN_COLLECTION;
        std::string JWT_SECRET_KEY;
        std::string JWT_ALGORITHM;
        std::string PASSWORD_SECRET_KEY;
        std::string PASSWORD_ALGORITHM;
        std::string SERVER_EMAIL;
        std::string BREVO_EMAIL_API;
        std::string BREVO_EMAIL_API_KEY;
        std::string DEFAULT_RESPONSE_TEMPLATE;
        std::string OTP_EMAIL_TEMPLATE;
    };
}

namespace KingsHeart
{
    inja::Environment& env_factory();
    const environment_t& get_env_t();
    std::vector<std::string> split(const std::string&, const std::string&);
    std::string generate_salt();
}

#endif