#include "Message.hpp"

namespace KingsHeart
{
    Message::Message(const std::string& key, const std::string& value)
    : _key(key), _value(value){}

    const std::string& Message::get_key()
    { return this->_key; }
    const std::string& Message::get_key() const
    { return this->_key; }

    const std::string& Message::get_value()
    { return this->_value; }
    const std::string& Message::get_value() const
    { return this->_value; }
}