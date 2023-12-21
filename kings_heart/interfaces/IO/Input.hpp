#ifndef __Input_H__
#define __Input_H__

#include <drogon/HttpRequest.h>
#include "AdminBagit.hpp"


namespace KingsHeart
{
    using HttpRequest = drogon::HttpRequestPtr;

    template<typename T>
    class Input
    {
    public:
        virtual const T& operator()() =0;
    };
}

#endif