#ifndef __HtmlHttpOutput_H__
#define __HtmlHttpOutput_H__

#include <memory>
#include <string>
#include <nlohmann/json.hpp>
#include <drogon/HttpResponse.h>
#include <inja/inja.hpp>
#include "Output.hpp"
#include "Functions.hpp"
#include "AdminBagit.hpp"
#include "File.hpp"
#include "MainLog.hpp"


namespace KingsHeart
{
    template<typename T>
    class HtmlHttpOutput : public Output<HttpResponse>
    {
    public:
        HtmlHttpOutput(const T&, const File&);
        HttpResponse& operator()() override;

    private:
        const T* __payload;
        const File* __file;
        static inja::Environment __INJA;
        HttpResponse __httpResponse;
    };
}

#include "HtmlHttpOutput.tpp"

#endif