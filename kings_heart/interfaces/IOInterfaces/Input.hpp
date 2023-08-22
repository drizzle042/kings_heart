#pragma once

#include "Payload.hpp"

namespace KingsHeart
{
    class Input
    {
    public:
        virtual Payload get_input() =0;
    };
}