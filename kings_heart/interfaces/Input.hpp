#pragma once

#include <memory>
#include "Payload.hpp"

using namespace KingsHeart;
namespace KingsHeart
{
    class Input
    {
    public:
        virtual std::shared_ptr<Payload> get_input() =0;
    };
}
