#ifndef __Objects_H__
#define __Objects_H__

#include <string>
#include <unordered_map>
#include <functional>
#include <jwt/algorithm.hpp>
#include "Enums.hpp"
#include "MainLog.hpp"


namespace KingsHeart
{
    std::unordered_map<std::string, jwt::algorithm> JWT_ALGO
    {
        {"HMAC-SHA-2-256", jwt::algorithm::HS256},
        {"HMAC-SHA-2-384", jwt::algorithm::HS384},
        {"HMAC-SHA-2-512", jwt::algorithm::HS512},
        {"RSA-SHA-2-256", jwt::algorithm::RS256},
        {"RSA-SHA-2-384", jwt::algorithm::RS384},
        {"RSA-SHA-2-512", jwt::algorithm::RS512},
        {"ECDSA-SHA-2-256", jwt::algorithm::ES256},
        {"ECDSA-SHA-2-384", jwt::algorithm::ES384},
        {"ECDSA-SHA-2-512", jwt::algorithm::ES512}
    };
}

namespace KingsHeart
{
    std::unordered_map<std::string, HASH_ALGORITHM> STR_TO_HASH_ALGORITHM
    {
        {"SCRYPT", HASH_ALGORITHM::SCRYPT}
    };

    std::unordered_map<HASH_ALGORITHM, std::string> HASH_ALGORITHM_TO_STR
    {
        {HASH_ALGORITHM::SCRYPT, "SCRYPT"}
    };
}

namespace KingsHeart
{
    std::unordered_map<EXCEPTION_LEVEL, std::function<void(const std::string&)>> LOG_EXCEPTION
    {
        {EXCEPTION_LEVEL::TRACE, MainLog::trace},
        {EXCEPTION_LEVEL::DEBUG, MainLog::debug},
        {EXCEPTION_LEVEL::INFO, MainLog::info},
        {EXCEPTION_LEVEL::WARN, MainLog::warn},
        {EXCEPTION_LEVEL::ERROR, MainLog::error},
        {EXCEPTION_LEVEL::CRITICAL, MainLog::critical}
    };
}

#endif