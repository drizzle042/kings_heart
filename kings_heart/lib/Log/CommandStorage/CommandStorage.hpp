#ifndef __CommandStorage_H__
#define __CommandStorage_H__

#include <string>
#include <stdexcept>
#include "Functions.hpp"
#include "LoggerRegistry.hpp"


namespace KingsHeart
{
    class CommandStorage
    {
    public:
        static void store(const std::string&);

    private:
        CommandStorage() =delete;
        static Logger _logger;
        static void _set_logger();
    };
}

#endif