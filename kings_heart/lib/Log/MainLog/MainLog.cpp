#include "MainLog.hpp"

namespace KingsHeart
{
    void MainLog::trace(const std::string& msg)
    {
        auto mainLogger = LoggerRegistry::get_logger("main_logger");
        if (!mainLogger)
        { throw std::runtime_error("main_logger is not a logger on this program"); }
        mainLogger->trace(msg);
    }

    void MainLog::debug(const std::string& msg)
    {
        auto mainLogger = LoggerRegistry::get_logger("main_logger");
        if (!mainLogger)
        { throw std::runtime_error("main_logger is not a logger on this program"); }
        mainLogger->debug(msg);
    }
    
    void MainLog::info(const std::string& msg)
    {
        auto mainLogger = LoggerRegistry::get_logger("main_logger");
        if (!mainLogger)
        { throw std::runtime_error("main_logger is not a logger on this program"); }
        mainLogger->info(msg);
    }
    
    void MainLog::warn(const std::string& msg)
    {
        auto mainLogger = LoggerRegistry::get_logger("main_logger");
        if (!mainLogger)
        { throw std::runtime_error("main_logger is not a logger on this program"); }
        mainLogger->warn(msg);
    }
    
    void MainLog::error(const std::string& msg)
    {
        auto mainLogger = LoggerRegistry::get_logger("main_logger");
        if (!mainLogger)
        { throw std::runtime_error("main_logger is not a logger on this program"); }
        mainLogger->error(msg);
    }
    
    void MainLog::critical(const std::string& msg)
    {
        auto mainLogger = LoggerRegistry::get_logger("main_logger");
        if (!mainLogger)
        { throw std::runtime_error("main_logger is not a logger on this program"); }
        mainLogger->critical(msg);
    }
}