#ifndef Objects_H
#define Objects_H

#include <string>
#include <stdexcept>


namespace KingsHeart
{
    std::string MAIN_DATABASE = "Kings_Heart_Main_Database";
    std::string MAIN_DATABASE_ADMIN_COLLECTION = "Admins";
    std::string MAIN_LOGGER = "Kings_Heart_Main_Logger";
    std::string COMMAND_STORAGE_LOGGER = "Kings_Heart_Command_Storage_Logger";
    std::string COMMAND_STORAGE_LOGGER_PATH = "Kings_Heart_Command_Storage_Logger_Path";
    std::string COMMAND_STORAGE_LOGGER_MAX_FILE_SIZE = "Kings_Heart_Command_Storage_Logger_Max_File_Size";
    std::string COMMAND_STORAGE_LOGGER_MAX_ALLOWED_FILES = "Kings_Heart_Command_Storage_Logger_Max_Allowed_Files";
    std::string JWT_SECRET_KEY = "Kings_Heart_JWT_Secret_Key";
    std::string JWT_ALGORITHM = "Kings_Heart_JWT_Algorithm";
    std::string DEFAULT_RESPONSE_TEMPLATE = "Kings_Heart_Default_Response_Template";
}

namespace KingsHeart
{
    std::string get_env_var(const std::string& var) noexcept(false)
    {
        char* env_name = std::getenv(var.c_str());

        if (!env_name)
        { throw std::runtime_error("No environment variable matches the name " + var); }

        return std::string(env_name);
    }
}

#endif