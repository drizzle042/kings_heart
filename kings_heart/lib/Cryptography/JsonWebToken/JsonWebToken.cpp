#include "JsonWebToken.hpp"


namespace KingsHeart
{
    JsonWebToken::JsonWebToken(const std::unordered_map<std::string, std::string>& data)
    : _data{data}
    {
        this->_secretKey = get_env_t().JWT_SECRET_KEY;

        static std::string algo{get_env_t().JWT_ALGORITHM};
        std::transform(algo.begin(), algo.end(), algo.begin(), [](unsigned char c){return std::toupper(c);});
        extern std::unordered_map<std::string, jwt::algorithm> JWT_ALGO;
        this->_algorithm = JWT_ALGO.find(algo) != JWT_ALGO.end() ? JWT_ALGO[algo] : JWT_ALGO["HS512"] ;
    }

    JsonWebToken::operator std::string()
    {
        auto payload = this->_data;
        auto headers = this->_metaData;

        jwt::jwt_object token{
            jwt::params::payload(std::move(payload)),
            jwt::params::secret(this->_secretKey),
            jwt::params::algorithm(this->_algorithm),
            jwt::params::headers(std::move(headers))
        };
        return token.signature();
    }

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
}