#ifndef __Unauthorized_H__
#define __Unauthorized_H__

#include <string>
#include "BaseException.hpp"
#include "Enums.hpp"

namespace KingsHeart
{
    class Unauthorized : public BaseException
    {
    public:
        explicit Unauthorized(const std::string&);
        unsigned short get_error_code() const noexcept override;
        EXCEPTION_LEVEL get_level() const noexcept override;
        const char* what() const noexcept override;
    
    private:
        Unauthorized() =delete;
        std::string __msg;
        unsigned short __STATUS_CODE = 401;
        EXCEPTION_LEVEL __level = EXCEPTION_LEVEL::INFO;
    };
}

#endif