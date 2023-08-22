#include "AbstractHttpOutput.hpp"


namespace KingsHeart
{
    AbstractHttpOutput::AbstractHttpOutput(const Payload& output)
    : _output{output}{}

    drogon::HttpResponsePtr AbstractHttpOutput::get_output()
    { return JsonHttpOutput{this->_output}.get_output(); }

    drogon::HttpResponsePtr AbstractHttpOutput::get_output(
        ResponseType respType, File&& fileTemplate
    )
    {
        drogon::HttpResponsePtr resp;
        switch (respType)
        {
            case ResponseType::HTML: resp = HtmlHttpOutput{this->_output, std::move(fileTemplate)}.get_output();
        }
        return resp;
    }
}