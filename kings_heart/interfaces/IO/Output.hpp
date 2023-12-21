#ifndef __Output_H__
#define __Output_H__

#include <drogon/HttpResponse.h>


namespace KingsHeart
{
    using HttpResponse = drogon::HttpResponsePtr;
    
    template<typename T>
    class Output
    {
    public:
        virtual T& operator()() =0;
    };
}

#endif