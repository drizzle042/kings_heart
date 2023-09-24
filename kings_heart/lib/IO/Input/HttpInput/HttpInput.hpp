#ifndef HttpInput_H
#define HttpInput_H

#include <string>
#include <string_view>
#include <vector>
#include <drogon/HttpRequest.h>
#include <jsoncpp/json/value.h>
#include "Input.hpp"
#include "Bagit.hpp"


namespace KingsHeart
{
    class HttpInput : public Input
    {
    private:
        HttpRequest _request;
        PayloadBuilder _payloadBuilder;
        std::shared_ptr<Payload> _payload;
        
    public:
        explicit HttpInput(HttpRequest);

        HttpInput& add_required_meta_datum_keys(const std::vector<std::string>&);
        HttpInput& add_required_message_keys(const std::vector<std::string>&);
        const Payload& get_input() override;
    };
}

#endif