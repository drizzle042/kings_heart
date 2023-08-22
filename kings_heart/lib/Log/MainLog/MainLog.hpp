#pragma once

#include <string>
#include <stdexcept>
#include "LoggerRegistry.hpp"

namespace KingsHeart
{
    class MainLog
    {
    private:
        MainLog() =default;

    public:
        static void trace(const std::string&);
        static void debug(const std::string&);
        static void info(const std::string&);
        static void warn(const std::string&);
        static void error(const std::string&);
        static void critical(const std::string&);
    };
}