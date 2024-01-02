#include "MainLog.hpp"


namespace KingsHeart
{
    Logger MainLog::_logger;

    void MainLog::_set_logger()
    {
        if (MainLog::_logger == nullptr)
        {
            static std::string loggerName{get_env_t().MAIN_LOGGER};
            MainLog::_logger = LoggerRegistry::get_logger(loggerName);
            if (MainLog::_logger == nullptr)
            { throw std::runtime_error(loggerName + " is not a logger on this program"); }
        }
    }

    void MainLog::trace(const std::string& msg)
    {
        MainLog::_set_logger();
        MainLog::_logger->trace(msg);
    }

    void MainLog::debug(const std::string& msg)
    {
        MainLog::_set_logger();
        MainLog::_logger->debug(msg);
    }
    
    void MainLog::info(const std::string& msg)
    {
        MainLog::_set_logger();
        MainLog::_logger->info(msg);
    }
    
    void MainLog::warn(const std::string& msg)
    {
        MainLog::_set_logger();
        MainLog::_logger->warn(msg);
    }
    
    void MainLog::error(const std::string& msg)
    {
        MainLog::_set_logger();
        MainLog::_logger->error(msg);
    }
    
    void MainLog::critical(const std::string& msg)
    {
        MainLog::_set_logger();
        MainLog::_logger->critical(msg);
    }
}