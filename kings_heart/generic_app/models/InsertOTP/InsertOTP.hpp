#ifndef __InsertOTP_H__
#define __InsertOTP_H__

#include <nlohmann/json.hpp>
#include "Command.hpp"


namespace KingsHeart
{
    template<typename T>
    class InsertOTPCommand : public Command<T>
    {
    public:
        explicit InsertOTPCommand(const nlohmann&);
        const T& operator()() override;

    private:
        const nlohmann::json* __query;
        T __output;
    };
}

#include "InsertOTP.tpp"

#endif