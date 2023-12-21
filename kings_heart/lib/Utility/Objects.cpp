#ifndef __Objects_H__
#define __Objects_H__

#include <string>
#include <stdexcept>
#include <unordered_map>
#include <functional>
#include <jwt/algorithm.hpp>
#include "Enums.hpp"
#include "MainLog.hpp"


namespace KingsHeart
{
    std::string MAIN_LOGGER = "Kings_Heart_Main_Logger";
    std::string COMMAND_STORAGE_LOGGER = "Kings_Heart_Command_Storage_Logger";
    std::string COMMAND_STORAGE_LOGGER_PATH = "Kings_Heart_Command_Storage_Logger_Path";
    std::string COMMAND_STORAGE_LOGGER_MAX_FILE_SIZE = "Kings_Heart_Command_Storage_Logger_Max_File_Size";
    std::string COMMAND_STORAGE_LOGGER_MAX_ALLOWED_FILES = "Kings_Heart_Command_Storage_Logger_Max_Allowed_Files";
}

namespace KingsHeart
{
    std::string MAIN_DATABASE_SERVER_URI = "Kings_Heart_Main_Database_Server_URI";
    std::string MAIN_DATABASE = "Kings_Heart_Main_Database";
    std::string MAIN_DATABASE_ADMIN_COLLECTION = "Kings_Heart_Main_Database_Admin_Table";
}

namespace KingsHeart
{
    std::string JWT_SECRET_KEY = "Kings_Heart_JWT_Secret_Key";
    std::string JWT_ALGORITHM = "Kings_Heart_JWT_Algorithm";
    std::string PASSWORD_SECRET_KEY = "Kings_Heart_Password_Secret_Key";
    std::string PASSWORD_ALGORITHM = "Kings_Heart_Password_Algorithm";
}

namespace KingsHeart
{
    std::string Brevo_Email_API = "Kings_Heart_Brevo_Email_API";
    std::string Brevo_Email_API_Key = "Kings_Heart_Brevo_Email_API_Key";
}

namespace KingsHeart
{
    std::string DEFAULT_RESPONSE_TEMPLATE = "Kings_Heart_Default_Response_Template";
    std::string OTP_EMAIL_TEMPLATE = "Kings_Heart_OTP_Email_Template";
}

namespace KingsHeart
{
    std::unordered_map<std::string, jwt::algorithm> JWT_ALGO
    {
        {"HMAC-SHA-2-256", jwt::algorithm::HS256},
        {"HMAC-SHA-2-384", jwt::algorithm::HS384},
        {"HMAC-SHA-2-512", jwt::algorithm::HS512},
        {"RSA-SHA-2-256", jwt::algorithm::RS256},
        {"RSA-SHA-2-384", jwt::algorithm::RS384},
        {"RSA-SHA-2-512", jwt::algorithm::RS512},
        {"ECDSA-SHA-2-256", jwt::algorithm::ES256},
        {"ECDSA-SHA-2-384", jwt::algorithm::ES384},
        {"ECDSA-SHA-2-512", jwt::algorithm::ES512}
    };
}

namespace KingsHeart
{
    std::unordered_map<std::string, HASH_ALGORITHM> STR_TO_HASH_ALGORITHM
    {
        {"SCRYPT", HASH_ALGORITHM::SCRYPT}
    };

    std::unordered_map<HASH_ALGORITHM, std::string> HASH_ALGORITHM_TO_STR
    {
        {HASH_ALGORITHM::SCRYPT, "SCRYPT"}
    };
}

namespace KingsHeart
{
    std::unordered_map<EXCEPTION_LEVEL, std::function<void(const std::string&)>> LOG_EXCEPTION
    {
        {EXCEPTION_LEVEL::TRACE, MainLog::trace},
        {EXCEPTION_LEVEL::DEBUG, MainLog::debug},
        {EXCEPTION_LEVEL::INFO, MainLog::info},
        {EXCEPTION_LEVEL::WARN, MainLog::warn},
        {EXCEPTION_LEVEL::ERROR, MainLog::error},
        {EXCEPTION_LEVEL::CRITICAL, MainLog::critical}
    };
}

#endif