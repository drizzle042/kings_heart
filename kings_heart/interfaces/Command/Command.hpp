#ifndef __Command_H__
#define __Command_H__


namespace KingsHeart
{
    template<typename T>
    class Command
    {
    public:
        virtual const T& operator()() =0;
    };
}

#endif