#pragma once

#include <string>
#include "Payload.hpp"

namespace KingsHeart
{
    class PayloadSerializer
    {
    public:
        virtual std::string serialize(const Payload&) =0;
        virtual Payload deserialize(const std::string&) =0;
        virtual void clear() =0;
    };
}