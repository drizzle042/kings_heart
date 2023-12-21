#include "BadRequest.hpp"


namespace KingsHeart
{
    BadRequest::BadRequest(const std::string& message)
    : __msg{message} {}

    unsigned short BadRequest::get_error_code() const noexcept
    { return this->__STATUS_CODE; }
    
    EXCEPTION_LEVEL BadRequest::get_level()  const noexcept
    { return this->__level; }

    const char* BadRequest::what() const noexcept
    { return this->__msg.data(); }
}