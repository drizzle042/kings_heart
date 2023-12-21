#ifndef __JsonWebToken_H__
#define __JsonWebToken_H__

#include <unordered_map>
#include <string>
#include <utility>
#include <algorithm>
#include <cctype>
#include <jwt/jwt.hpp>
#include "Functions.hpp"


namespace KingsHeart
{
    class JsonWebToken
    {
    public:
        explicit JsonWebToken(const std::unordered_map<std::string, std::string>&);
        operator std::string();
        JsonWebToken& add_data(const std::unordered_map<std::string, std::string>&);
        JsonWebToken& remove_data(const std::string&);
        JsonWebToken& add_meta_datum(const std::unordered_map<std::string, std::string>&);
        JsonWebToken& remove_meta_datum(const std::string&);

    private:
        std::string _secretKey;
        jwt::algorithm _algorithm;
        std::unordered_map<std::string, std::string> _data;
        std::unordered_map<std::string, std::string> _metaData;
    };
}

#endif