#ifndef HttpOutput_H
#define HttpOutput_H

#include <memory>
#include "Bagit.hpp"
#include "Output.hpp"
#include "File.hpp"
#include "JsonHttpOutput.hpp"
#include "HtmlHttpOutput.hpp"


namespace KingsHeart
{
    class HttpOutput : public Output<HttpResponse>
    {
    private:
        std::shared_ptr<Payload> _payload;
        std::shared_ptr<Output<HttpResponse>> _outputFormat;

    public:
        HttpOutput(const Payload&);

        HttpOutput& set_output_format(const Output<HttpResponse>&);
        HttpOutput& set_output_format(const MetaDatum&, const File&);
        const HttpResponse& get_output() override;
    };
}

#endif