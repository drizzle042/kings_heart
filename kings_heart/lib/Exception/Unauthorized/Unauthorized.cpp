#include "Unauthorized.hpp"


namespace KingsHeart
{
    Unauthorized::Unauthorized(const std::string& message)
    : __msg{message} {}

    unsigned short Unauthorized::get_error_code() const noexcept
    { return this->__STATUS_CODE; }
    
    EXCEPTION_LEVEL Unauthorized::get_level()  const noexcept
    { return this->__level; }

    const char* Unauthorized::what() const noexcept
    { return this->__msg.data(); }
}