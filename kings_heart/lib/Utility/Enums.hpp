#ifndef __Enums_H__
#define __Enums_H__


namespace KingsHeart
{
    enum class HTTP_OUTPUT 
    {
        CBOR, 
        JSON, 
        HTML
    };

    enum class EXCEPTION_LEVEL
    {
        TRACE,
        DEBUG,
        INFO,
        WARN,
        ERROR,
        CRITICAL
    };

    enum class HASH_ALGORITHM
    {
        SCRYPT
    };
}

#endif