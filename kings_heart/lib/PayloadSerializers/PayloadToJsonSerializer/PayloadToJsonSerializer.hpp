#ifndef PayloadToJsonSerializer_H
#define PayloadToJsonSerializer_H

#include <string>
#include <stdexcept>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/reader.h>
#include "PayloadSerializer.hpp"
#include "Bagit.hpp"


namespace KingsHeart
{
    class PayloadToJsonSerializer : public PayloadSerializer
    {
    public:
        std::string serialize(const Payload&) override;
        Payload deserialize(const std::string&) override;
    };
}

#endif