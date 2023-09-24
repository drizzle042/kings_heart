#ifndef Input_H
#define Input_H

#include <drogon/HttpRequest.h>
#include "Bagit.hpp"


namespace KingsHeart
{
    using HttpRequest = drogon::HttpRequestPtr;

    class Input
    {
    public:
        virtual const Payload& get_input() =0;
    };
}

#endif