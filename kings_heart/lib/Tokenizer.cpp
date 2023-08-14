#include "Tokenizer.hpp"

namespace KingsHeart
{
    Token::Token(const std::unordered_map<std::string, std::string>& data)
    : _data{data}{}

    void Token::add_data(std::unordered_map<std::string, std::string>&& data)
    { this->_data = std::move(data); }

    void Token::remove_data(const std::string& key)
    { this->_data.erase(key); }


    void Token::add_header(std::unordered_map<std::string, std::string>&& header)
    { this->_headers = std::move(header); }

    void Token::remove_header(const std::string& key)
    { this->_data.erase(key); }

    std::string Token::get_token()
    {
        jwt::jwt_object token{
            jwt::params::payload(std::move(_data)),
            jwt::params::secret("12345"),
            jwt::params::algorithm(jwt::algorithm::HS256),
            jwt::params::headers(std::move(_headers))
        };
        return token.signature();
    }
}