#include "Payload.hpp"


namespace KingsHeart
{
    const MetaDatum* Payload::get_meta_datum_by_key(const std::string& key) const
    {
        auto it = this->_metaData.find(key);
        return (it != this->_metaData.end()) ? &it->second : nullptr;
    }

    const MetaDatum* Payload::get_meta_datum_by_value(const std::string& value) const
    {
        for (const auto& pair : this->_metaData)
        {
            if (pair.second.get_value() == value) {
                return &pair.second;
            }
        }
        return nullptr;
    }

    const std::unordered_set<const MetaDatum*> Payload::get_meta_data() const
    {
        std::unordered_set<const MetaDatum*> metaData;
        for (auto& pair : this->_metaData)
        {
            metaData.insert(&pair.second);
        }
        return metaData;
    }

    const std::unordered_set<std::string> Payload::get_required_meta_datum_keys() const
    { return this->_requiredMetaDatumKeys; }


    const Message* Payload::get_message_by_key(const std::string& key) const
    {
        auto it = this->_messages.find(key);
        return (it != this->_messages.end()) ? &it->second : nullptr;
    }

    const Message* Payload::get_message_by_value(const std::string& value) const
    {
        for (const auto& pair : this->_messages)
        {
            if (pair.second.get_value() == value) {
                return &pair.second;
            }
        }
        return nullptr;
    }

    const std::unordered_set<const Message*> Payload::get_messages() const
    {
        std::unordered_set<const Message*> messages;
        for (auto& pair : this->_messages)
        {
            messages.insert(&pair.second);
        }
        return messages;
    }

    const std::unordered_set<std::string> Payload::get_required_message_keys() const
    { return this->_requiredMessageKeys; }
}