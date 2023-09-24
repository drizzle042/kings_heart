#ifndef Command_H
#define Command_H

#include "Bagit.hpp"


namespace KingsHeart
{
    class Command
    {
    public:
        virtual Payload execute() =0;
    };
}

#endif