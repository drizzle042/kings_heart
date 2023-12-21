#ifndef __HttpInput_H__
#define __HttpInput_H__

#include <nlohmann/json.hpp>
#include "Input.hpp"
#include "Enums.hpp"


namespace KingsHeart
{
    template<typename T>
    class HttpInput : public Input<T>
    {
    public:
        explicit HttpInput(const HttpRequest&);
        const T& operator()() override;
        HTTP_OUTPUT get_output_type();

    private:
        HttpRequest _request;
        T _input;
    };
}

#include "HttpInput.tpp"

#endif