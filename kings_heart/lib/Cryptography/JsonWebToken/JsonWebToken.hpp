#pragma once

#include <unordered_map>
#include <string>
#include <utility>
#include <jwt/jwt.hpp>

namespace KingsHeart
{
    class JsonWebToken
    {
    private:
        std::unordered_map<std::string, std::string> _data;
        std::unordered_map<std::string, std::string> _metaData;
        jwt::algorithm _alg = jwt::algorithm::HS256;
        std::string _secretKey = "12345";
        
    public:
        JsonWebToken(const std::unordered_map<std::string, std::string>&);

        void add_data(std::unordered_map<std::string, std::string>&&);
        void remove_data(const std::string&);
        void add_meta_datum(std::unordered_map<std::string, std::string>&&);
        void remove_meta_datum(const std::string&);

        std::string get_token();
    };
}