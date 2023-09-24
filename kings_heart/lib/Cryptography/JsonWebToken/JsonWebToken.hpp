#ifndef JsonWebToken_H
#define JsonWebToken_H

#include <unordered_map>
#include <string>
#include <utility>
#include <jwt/jwt.hpp>


namespace KingsHeart
{
    class JsonWebToken
    {
    private:
        std::string _secretKey;
        std::string _algorithm;
        std::unordered_map<std::string, std::string> _data;
        std::unordered_map<std::string, std::string> _metaData;
        
    public:
        explicit JsonWebToken(const std::unordered_map<std::string, std::string>&);

        JsonWebToken& add_data(const std::unordered_map<std::string, std::string>&);
        JsonWebToken& remove_data(const std::string&);
        JsonWebToken& add_meta_datum(const std::unordered_map<std::string, std::string>&);
        JsonWebToken& remove_meta_datum(const std::string&);

        std::string get_token();
    };
}

#endif