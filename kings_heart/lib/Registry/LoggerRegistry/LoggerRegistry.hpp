#pragma once

#include <memory>
#include <string>
#include <spdlog/spdlog.h>


namespace KingsHeart
{
    using Logger = std::shared_ptr<spdlog::logger>;

    class LoggerRegistry
    {
    public:
        static Logger get_logger(const std::string&);

    private:
        LoggerRegistry() =delete;
    };
}