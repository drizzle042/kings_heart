#ifndef __KeyDerivation_H__
#define __KeyDerivation_H__

#include <string>


namespace KingsHeart
{
    class KDFunction
    {
    public:
        virtual operator std::string() =0;
        virtual bool operator==(const std::string&) =0;
        virtual bool operator==(const KDFunction&) =0;
        virtual bool operator!=(const std::string&) =0;
        virtual bool operator!=(const KDFunction&) =0;
    };
}

#endif