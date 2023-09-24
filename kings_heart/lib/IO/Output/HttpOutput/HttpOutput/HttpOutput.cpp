#include "HttpOutput.hpp"


namespace KingsHeart
{
    HttpOutput::HttpOutput(const Payload& payload)
    : _payload{std::shared_ptr<Payload>{const_cast<Payload*>(&payload)}}, 
      _outputFormat{std::make_shared<JsonHttpOutput>(payload)} {}
    
    HttpOutput& HttpOutput::set_output_format(const Output<HttpResponse>& outputFormat)
    {
        this->_outputFormat = std::shared_ptr<Output<HttpResponse>>{
            const_cast<Output<HttpResponse>*>(&outputFormat)};
        return *this;
    }

    extern std::string get_env_var(const std::string&) noexcept(false);
    extern std::string DEFAULT_RESPONSE_TEMPLATE;
    
    HttpOutput& HttpOutput::set_output_format(
        const MetaDatum& resType,
        const File& outputTemplate = File{get_env_var(DEFAULT_RESPONSE_TEMPLATE)})
    {
        if (resType.read() == "application/json")
        { this->_outputFormat = std::make_shared<JsonHttpOutput>(*this->_payload); }

        if (resType.read() == "text/html")
        { 
            this->_outputFormat = std::make_shared<HtmlHttpOutput>(
                *this->_payload, const_cast<File&>(outputTemplate)); 
        }
        return *this;
    }

    const HttpResponse& HttpOutput::get_output()
    { return this->_outputFormat->get_output(); }
}