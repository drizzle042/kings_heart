#ifndef __CborHttpOutput_H__
#define __CborHttpOutput_H__

#include <memory>
#include <nlohmann/json.hpp>
#include "Output.hpp"
#include "AdminBagit.hpp"


namespace KingsHeart
{
    template<typename T>
    class CborHttpOutput : public Output<HttpResponse>
    {
    public:
        explicit CborHttpOutput(const T&);
        HttpResponse& operator()() override;

    private:
        const T* _payload;
        HttpResponse _httpResponse;
    };
}

#include "CborHttpOutput.tpp"

#endif