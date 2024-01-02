#ifndef __HtmlHttpOutput_H__
#define __HtmlHttpOutput_H__

#include <string>
#include <inja/inja.hpp>
#include <drogon/HttpResponse.h>
#include "Output.hpp"
#include "Functions.hpp"
#include "File.hpp"


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
        HttpResponse __httpResponse;
    };
}

#include "HtmlHttpOutput.tpp"

#endif