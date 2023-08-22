#pragma once

#include <memory>
#include <string>
#include <stdexcept>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/reader.h>
#include "PayloadSerializer.hpp"
#include "Payload.hpp"
#include "PayloadBuilder.hpp"
#include "MetaDatum.hpp"
#include "Message.hpp"

namespace KingsHeart
{
    class PayloadToJsonSerializer : public PayloadSerializer
    {
    private:
        std::shared_ptr<std::string> _jsonString;
        std::shared_ptr<Payload> _payload;
        PayloadBuilder _payloadBuilder;

    public:
        PayloadToJsonSerializer() =default;
        ~PayloadToJsonSerializer() =default;

        std::string serialize(const Payload&) override;
        Payload deserialize(const std::string&) override;
        void clear() override;
    };
}