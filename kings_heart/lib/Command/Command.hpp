#pragma once

#include <string>
#include "Payload.hpp"
#include "CommandStorage.hpp"
#include "PayloadToJsonSerializer.hpp"

namespace KingsHeart
{
    class Command
    {
    public:
        virtual Payload execute() =0;
        virtual void store(const std::string&, const Payload&);
    };
}