#ifndef JsonHttpOutput_H
#define JsonHttpOutput_H

#include <memory>
#include <jsoncpp/json/json.h>
#include "Output.hpp"
#include "Bagit.hpp"


namespace KingsHeart
{
    class JsonHttpOutput : public Output<HttpResponse>
    {
    private:
        std::shared_ptr<Payload> _payload;
        HttpResponse _httpResponse;
    
    public:
        explicit JsonHttpOutput(const Payload&);
        HttpResponse& get_output() override;
    };
}

#endif