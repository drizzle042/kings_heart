#include "HtmlHttpOutput.hpp"


namespace KingsHeart
{
    HtmlHttpOutput::HtmlHttpOutput(const Payload& payload, File& file)
    : _payload{std::make_shared<Payload>(payload)}, 
      _file{&file} {}

    HttpResponse& HtmlHttpOutput::get_output()
    {
        if (this->_httpResponse == nullptr)
        {
            this->_httpResponse = drogon::HttpResponse::newHttpResponse();

            for (auto& metaDatum : this->_payload->get_meta_data())
            { this->_httpResponse->addHeader(metaDatum.first, metaDatum.second.read()); }

            inja::json json;
            for (auto& msg : this->_payload->get_messages())
            { json[msg.first] = msg.second.read(); }
            
            this->_httpResponse->setBody(inja::render(this->_file->get_text_content(), json));
        }
        return this->_httpResponse;
    }
}