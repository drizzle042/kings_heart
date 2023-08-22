#include "MetaDatum.hpp"

namespace KingsHeart
{
    MetaDatum::MetaDatum(const std::string& key, const std::string& value)
    : _key(key), _value(value){}

    const std::string& MetaDatum::get_key() 
    { return this->_key; }
    const std::string& MetaDatum::get_key() const
    { return this->_key; }

    const std::string& MetaDatum::get_value()
    { return this->_value; }
    const std::string& MetaDatum::get_value() const
    { return this->_value; }
}