#pragma once

#include <string>
#include <drogon/HttpResponse.h>
#include <jsoncpp/json/value.h>
#include <inja/inja.hpp>
#include "Output.hpp"
#include "Payload.hpp"
#include "File.hpp"


namespace KingsHeart
{
    class HtmlHttpOutput : public Output<drogon::HttpResponsePtr>
    {
    private:
        Payload _payload;
        File _file;
        drogon::HttpResponsePtr _httpResponsePtr;

    public:
        HtmlHttpOutput(const Payload&, File&&);
        
        drogon::HttpResponsePtr get_output() override;
    };
}