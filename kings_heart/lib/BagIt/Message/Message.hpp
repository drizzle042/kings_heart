#pragma once

#include <string>

namespace KingsHeart
{
    class Message {
    private:
        std::string _key;
        std::string _value;

    public:
        Message(const std::string& key, const std::string& value);

        const std::string& get_key();
        const std::string& get_key() const;

        const std::string& get_value();
        const std::string& get_value() const;
    };
}