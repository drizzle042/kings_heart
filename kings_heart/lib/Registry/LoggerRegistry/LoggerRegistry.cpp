#include "LoggerRegistry.hpp"


namespace KingsHeart
{
    Logger LoggerRegistry::get_logger(const std::string& key)
    { return spdlog::get(key); }
}