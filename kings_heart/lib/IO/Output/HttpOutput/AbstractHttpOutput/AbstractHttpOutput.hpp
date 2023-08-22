#pragma once

#include <drogon/HttpResponse.h>
#include "Payload.hpp"
#include "File.hpp"
#include "Output.hpp"
#include "JsonHttpOutput.hpp"
#include "HtmlHttpOutput.hpp"


namespace KingsHeart
{
    enum class ResponseType {PDF, HTML, TEXT};

    class AbstractHttpOutput : public Output<drogon::HttpResponsePtr>
    {
    private:
        Payload _output;

    public:
        AbstractHttpOutput(const Payload&);

        drogon::HttpResponsePtr get_output() override;
        drogon::HttpResponsePtr get_output(ResponseType, File&&);
    };
}