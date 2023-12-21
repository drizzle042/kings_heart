#ifndef __ExceptionHandler_H__
#define __ExceptionHandler_H__

#include <string>
#include <format>
#include <drogon/drogon.h>
#include "Enums.hpp"
#include "BaseException.hpp"
#include "GenericBagit.hpp"
#include "HttpOutput.hpp"


namespace KingsHeart
{
    class ExceptionHandler
    {
    public:
        void operator()(
            const std::exception&, 
            const drogon::HttpRequestPtr&, 
            drogon::AdviceCallback&&
        );
    };
}

#endif