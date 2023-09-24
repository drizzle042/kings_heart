#ifndef PayloadSerializer_H
#define PayloadSerializer_H

#include <string>
#include "Bagit.hpp"


namespace KingsHeart
{
    class PayloadSerializer
    {
    public:
        virtual std::string serialize(const Payload&) =0;
        virtual Payload deserialize(const std::string&) =0;
    };
}

#endif