#pragma once

#include <unordered_map>
#include <string>
#include <utility>
#include <jwt/jwt.hpp>

namespace KingsHeart
{
    class Token
    {
    private:
        std::unordered_map<std::string, std::string> _data;
        std::unordered_map<std::string, std::string> _headers;
        jwt::algorithm _alg = jwt::algorithm::HS256;
        std::string _secretKey = "12345";
    public:
        Token() =default;
        Token(const std::unordered_map<std::string, std::string>&);
        ~Token() =default;

        void add_data(std::unordered_map<std::string, std::string>&&);
        void remove_data(const std::string&);
        void add_header(std::unordered_map<std::string, std::string>&&);
        void remove_header(const std::string&);

        std::string get_token();
    };
}