#ifndef __BaseException_H__
#define __BaseException_H__

#include <exception>
#include "Enums.hpp"

namespace KingsHeart
{
    class BaseException : public std::exception
    {
    public:
        virtual unsigned short get_error_code() const noexcept =0;
        virtual EXCEPTION_LEVEL get_level() const noexcept =0;
        virtual const char* what() const noexcept =0;
    };
}

#endif