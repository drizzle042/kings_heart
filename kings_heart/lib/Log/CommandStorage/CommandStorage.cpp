#include "CommandStorage.hpp"


namespace KingsHeart
{
    Logger CommandStorage::_logger;

    void CommandStorage::_set_logger()
    {
        if (CommandStorage::_logger == nullptr)
        {
            static std::string loggerName{get_env_t().COMMAND_STORAGE_LOGGER};
            CommandStorage::_logger = LoggerRegistry::get_logger(loggerName);
            if (CommandStorage::_logger == nullptr)
            { throw std::runtime_error(loggerName + " is not a logger on this program"); }
        }        
    }

    void CommandStorage::store(const std::string& msg)
    {
        CommandStorage::_set_logger();
        CommandStorage::_logger->info(msg);
    }
}