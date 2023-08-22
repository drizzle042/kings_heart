#include "HtmlHttpOutput.hpp"
#include "MainLog.hpp"


namespace KingsHeart
{
    HtmlHttpOutput::HtmlHttpOutput(const Payload& payload, File&& file)
    : _payload{payload}, _file{std::move(file)} {}

    drogon::HttpResponsePtr HtmlHttpOutput::get_output()
    {
        if (this->_httpResponsePtr == nullptr)
        {
            this->_httpResponsePtr = drogon::HttpResponse::newHttpResponse();

            for (const auto metaDatum : this->_payload.get_meta_data())
            {
                this->_httpResponsePtr->addHeader(metaDatum->get_key(), metaDatum->get_value());
            }

            inja::json json;
            for (const auto msg : this->_payload.get_messages())
            {
                json[msg->get_key()] = msg->get_value();
            }
            
            this->_httpResponsePtr->setBody(inja::render(this->_file.get_content(), json));
        }
        return this->_httpResponsePtr;
    }
}