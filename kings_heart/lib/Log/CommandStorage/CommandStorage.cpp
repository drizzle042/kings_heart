#include "CommandStorage.hpp"


namespace KingsHeart
{
    void CommandStorage::store(const std::string& msg)
    {
        auto commandStorageLogger = LoggerRegistry::get_logger("command_storage_logger");

        if (!commandStorageLogger)
        { throw std::runtime_error("command_storage_logger is not a logger on this program"); }
        
        commandStorageLogger->info(msg);
        commandStorageLogger->flush();
    }
}