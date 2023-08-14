#pragma once

#include <memory>
#include <drogon/HttpResponse.h>
#include <jsoncpp/json/value.h>
#include "Payload.hpp"

namespace KingsHeart
{
    class HttpOutput
    {
    private:
        drogon::HttpResponsePtr _httpResponsePtr;
        Payload _payload;
    
    public:
        HttpOutput() =default;
        HttpOutput(const Payload&);
        ~HttpOutput() =default;

        drogon::HttpResponsePtr get_output();
    };
}