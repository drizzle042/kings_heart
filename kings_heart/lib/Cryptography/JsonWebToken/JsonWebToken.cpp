#include "JsonWebToken.hpp"

namespace KingsHeart
{
    extern std::string get_env_var(const std::string&) noexcept(false);
    extern std::string JWT_SECRET_KEY;
    extern std::string JWT_ALGORITHM;

    JsonWebToken::JsonWebToken(const std::unordered_map<std::string, std::string>& data)
    : _data{data}, 
    _secretKey{get_env_var(JWT_SECRET_KEY)}, 
    _algorithm{get_env_var(JWT_ALGORITHM)}{}


    JsonWebToken& JsonWebToken::add_data(const std::unordered_map<std::string, std::string>& data)
    { 
        this->_data.insert(data.begin(), data.end()); 
        return *this;
    }

    JsonWebToken& JsonWebToken::remove_data(const std::string& key)
    { 
        this->_data.erase(key); 
        return *this;
    }


    JsonWebToken& JsonWebToken::add_meta_datum(const std::unordered_map<std::string, std::string>& metaDatum)
    { 
        this->_metaData.insert(metaDatum.begin(), metaDatum.end()); 
        return *this;
    }

    JsonWebToken& JsonWebToken::remove_meta_datum(const std::string& key)
    { 
        this->_data.erase(key); 
        return *this;
    }


    std::string JsonWebToken::get_token()
    {
        jwt::jwt_object token{
            jwt::params::payload(std::move(this->_data)),
            jwt::params::secret(this->_secretKey),
            jwt::params::algorithm(this->_algorithm),
            jwt::params::headers(std::move(this->_metaData))
        };
        return token.signature();
    }
}