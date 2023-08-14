#include "Payload.hpp"

namespace KingsHeart
{
    class Command
    {
    public:
        virtual Payload execute() =0;
    };
}