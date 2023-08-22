#include "LoggerRegistry.hpp"


namespace KingsHeart
{
    std::shared_ptr<spdlog::logger> LoggerRegistry::get_logger(const std::string& key)
    { return spdlog::get(key); }
}