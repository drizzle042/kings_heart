#include "JsonWebToken.hpp"

namespace KingsHeart
{
    JsonWebToken::JsonWebToken(const std::unordered_map<std::string, std::string>& data)
    : _data{data}{}


    void JsonWebToken::add_data(std::unordered_map<std::string, std::string>&& data)
    { this->_data = std::move(data); }

    void JsonWebToken::remove_data(const std::string& key)
    { this->_data.erase(key); }


    void JsonWebToken::add_meta_datum(std::unordered_map<std::string, std::string>&& metaDatum)
    { this->_metaData = std::move(metaDatum); }

    void JsonWebToken::remove_meta_datum(const std::string& key)
    { this->_data.erase(key); }


    std::string JsonWebToken::get_token()
    {
        jwt::jwt_object token{
            jwt::params::payload(std::move(this->_data)),
            jwt::params::secret(this->_secretKey),
            jwt::params::algorithm(this->_alg),
            jwt::params::headers(std::move(this->_metaData))
        };
        return token.signature();
    }
}