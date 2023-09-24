#ifndef Output_H
#define Output_H

#include <drogon/HttpResponse.h>


namespace KingsHeart
{
    using HttpResponse = drogon::HttpResponsePtr;
    
    template<typename T>
    class Output
    {
    public:
        virtual const T& get_output() =0;
    };
}

#endif