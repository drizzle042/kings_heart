#pragma once


namespace kings_heart
{
    class UserInterface
    {
        public:
            virtual bool is_authenticated() =0;
    };
}