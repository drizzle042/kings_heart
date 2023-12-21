#ifndef __BadRequest_H__
#define __BadRequest_H__

#include <string>
#include "BaseException.hpp"
#include "Enums.hpp"

namespace KingsHeart
{
    class BadRequest : public BaseException
    {
    public:
        explicit BadRequest(const std::string&);
        unsigned short get_error_code() const noexcept override;
        EXCEPTION_LEVEL get_level() const noexcept override;
        const char* what() const noexcept override;
    
    private:
        BadRequest() =delete;
        std::string __msg;
        unsigned short __STATUS_CODE = 400;
        EXCEPTION_LEVEL __level = EXCEPTION_LEVEL::INFO;
    };
}

#endif