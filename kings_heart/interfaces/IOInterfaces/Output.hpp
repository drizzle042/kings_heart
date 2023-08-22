#pragma once


namespace KingsHeart
{
    template<typename T>
    class Output
    {
    public:
        virtual T get_output() =0;
    };
}