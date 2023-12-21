#ifndef __HttpOutput_H__
#define __HttpOutput_H__

#include <memory>
#include <string>
#include "Functions.hpp"
#include "Enums.hpp"
#include "Output.hpp"
#include "CborHttpOutput.hpp"
#include "JsonHttpOutput.hpp"
#include "HtmlHttpOutput.hpp"
#include "FileRegistry.hpp"
#include "File.hpp"


namespace KingsHeart
{
    template<typename T>
    class HttpOutput : public Output<HttpResponse>
    {
    public:
        explicit HttpOutput(const T&, HTTP_OUTPUT);
        explicit HttpOutput(const T&, HTTP_OUTPUT, const File&);
        HttpResponse& operator()() override;

    private:
        std::shared_ptr<Output<HttpResponse>> __outputFormat;
    };
}

#include "HttpOutput.tpp"

#endif