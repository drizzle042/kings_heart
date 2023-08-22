#pragma once

#include <drogon/HttpResponse.h>
#include <jsoncpp/json/json.h>
#include "Output.hpp"
#include "Payload.hpp"


namespace KingsHeart
{
    class JsonHttpOutput : public Output<drogon::HttpResponsePtr>
    {
    private:
        Payload _payload;
        drogon::HttpResponsePtr _httpResponsePtr;
    
    public:
        JsonHttpOutput(const Payload&);

        drogon::HttpResponsePtr get_output() override;
    };
}