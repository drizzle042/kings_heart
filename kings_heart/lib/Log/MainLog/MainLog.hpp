#ifndef __MainLog_H__
#define __MainLog_H__

#include <string>
#include <stdexcept>
#include "Functions.hpp"
#include "LoggerRegistry.hpp"

namespace KingsHeart
{
    class MainLog
    {
    public:
        static void trace(const std::string&);
        static void debug(const std::string&);
        static void info(const std::string&);
        static void warn(const std::string&);
        static void error(const std::string&);
        static void critical(const std::string&);

    private:
        MainLog() =delete;
        static Logger _logger;
        static void _set_logger();
    };
}

#endif