#ifndef __JsonHttpOutput_H__
#define __JsonHttpOutput_H__

#include <memory>
#include <nlohmann/json.hpp>
#include "Output.hpp"
#include "AdminBagit.hpp"


namespace KingsHeart
{
    template<typename T>
    class JsonHttpOutput : public Output<HttpResponse>
    {
    public:
        explicit JsonHttpOutput(const T&);
        HttpResponse& operator()() override;

    private:
        const T* _payload;
        HttpResponse _httpResponse;
    };
}

#include "JsonHttpOutput.tpp"

#endif