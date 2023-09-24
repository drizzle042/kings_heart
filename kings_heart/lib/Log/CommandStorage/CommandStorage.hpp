#ifndef CommandStorage_H
#define CommandStorage_H

#include <string>
#include <stdexcept>
#include "LoggerRegistry.hpp"

namespace KingsHeart
{
    class CommandStorage
    {
    private:
        CommandStorage() =delete;
        static Logger _logger;
        static void _set_logger();

    public:
        static void store(const std::string&);
    };
}

#endif