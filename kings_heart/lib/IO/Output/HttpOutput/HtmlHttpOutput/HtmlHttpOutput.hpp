#ifndef HtmlHttpOutput_H
#define HtmlHttpOutput_H

#include <memory>
#include <string>
#include <drogon/HttpResponse.h>
#include <jsoncpp/json/value.h>
#include <inja/inja.hpp>
#include "Output.hpp"
#include "Bagit.hpp"
#include "File.hpp"


namespace KingsHeart
{
    class HtmlHttpOutput : public Output<HttpResponse>
    {
    private:
        std::shared_ptr<Payload> _payload;
        File* _file;
        HttpResponse _httpResponse;

    public:
        HtmlHttpOutput(const Payload&, File&);
        HttpResponse& get_output() override;
    };
}

#endif