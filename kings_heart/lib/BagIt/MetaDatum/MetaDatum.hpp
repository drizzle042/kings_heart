#pragma once

#include <string>

namespace KingsHeart
{
    class MetaDatum {
    public:
        MetaDatum(const std::string& key, const std::string& value);
        ~MetaDatum() =default;

        const std::string& get_key();
        const std::string& get_key() const;

        const std::string& get_value();
        const std::string& get_value() const;

    private:
        std::string _key;
        std::string _value;
    };
}