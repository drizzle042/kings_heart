#ifndef MainLog_H
#define MainLog_H

#include <string>
#include <stdexcept>
#include "LoggerRegistry.hpp"

namespace KingsHeart
{
    class MainLog
    {
    private:
        MainLog() =delete;
        static Logger _logger;
        static void _set_logger();

    public:
        static void trace(const std::string&);
        static void debug(const std::string&);
        static void info(const std::string&);
        static void warn(const std::string&);
        static void error(const std::string&);
        static void critical(const std::string&);
    };
}

#endif