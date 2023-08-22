#pragma once

#include <string>
#include <stdexcept>
#include "LoggerRegistry.hpp"

namespace KingsHeart
{
    class CommandStorage
    {
    private:
        CommandStorage() =default;

    public:
        static void store(const std::string&);
    };
}