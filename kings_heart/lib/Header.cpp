#include "Header.hpp"

namespace KingsHeart
{
    Header::Header(const std::string& key, const std::string& value)
    : _key(key), _value(value){}

    const std::string& Header::get_key() 
    { return this->_key; }
    const std::string& Header::get_key() const
    { return this->_key; }

    const std::string& Header::get_value()
    { return this->_value; }
    const std::string& Header::get_value() const
    { return this->_value; }
}