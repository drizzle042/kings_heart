#pragma once

#include <memory>
#include <string>
#include <spdlog/spdlog.h>


namespace KingsHeart
{
    class LoggerRegistry
    {
    private:
        LoggerRegistry() =default;

    public:
        static std::shared_ptr<spdlog::logger> get_logger(const std::string&);
    };
}