#include "Bagit.hpp"

namespace KingsHeart
{
    MetaDatum::MetaDatum(const std::string& value)
    : _metaDatum{value} {}

    const bool MetaDatum::operator == (const MetaDatum& metaDatum) const
    { return (this->_metaDatum == metaDatum._metaDatum); }

    MetaDatum::operator std::string () const
    { return this->_metaDatum; }

    [[deprecated("MetaDatum is now std::string convertible!")]]
    const std::string& MetaDatum::read() const
    { return this->_metaDatum; }

    // #######################################################

    Message::Message(const std::string& value)
    : _msg{value} {}

    const bool Message::operator == (const Message& msg) const
    { return (this->_msg == msg._msg); }

    Message::operator std::string () const
    { return this->_msg; }

    [[deprecated("Message is now std::string convertible!")]]
    const std::string& Message::read() const
    { return this->_msg; }

    // #######################################################

    const MetaDatum* Payload::get_meta_datum(const std::string& key) const
    {
        auto it = this->_metaData.find(key);
        return (it != this->_metaData.end()) ? &it->second : nullptr;
    }

    const std::unordered_map<std::string, MetaDatum>& Payload::get_meta_data() const
    { return this->_metaData; }

    const Message* Payload::get_message(const std::string& key) const
    {
        auto it = this->_messages.find(key);
        return (it != this->_messages.end()) ? &it->second : nullptr;
    }

    const std::unordered_map<std::string, Message>& Payload::get_messages() const
    { return this->_messages; }

    const bool Payload::operator == (const Payload& payload) const
    { return (this->_metaData == payload._metaData) && (this->_messages == payload._messages); }

    // #######################################################

    PayloadBuilder& PayloadBuilder::add_meta_datum(const std::string& key, const MetaDatum& metaDatum)
    { 
        this->_payload._metaData.emplace(key, metaDatum);
        return *this;
    }

    PayloadBuilder& PayloadBuilder::add_required_meta_data(const std::vector<std::string>& rMetaData)
    {
        this->_requiredMetaData.insert(
            this->_requiredMetaData.end(),
            rMetaData.begin(), rMetaData.end());
        return *this;
    }

    PayloadBuilder& PayloadBuilder::add_message(const std::string& key, const Message& msg)
    { 
        this->_payload._messages.emplace(key, msg);
        return *this;
    }

    PayloadBuilder& PayloadBuilder::add_required_messages(const std::vector<std::string>& rMessages)
    {
        this->_requiredMessages.insert(
            this->_requiredMessages.end(),
            rMessages.begin(), rMessages.end());
        return *this;
    }

    const Payload& PayloadBuilder::build() const
    {
        for (const auto& rMetaData : this->_requiredMetaData)
        {
            if (this->_payload._metaData.find(rMetaData) == this->_payload._metaData.end())
            {
                throw std::runtime_error(rMetaData + " metaDatum is required");
            }
        }
        for (const auto& rMsg : this->_requiredMessages)
        {
            if (this->_payload._messages.find(rMsg) == this->_payload._messages.end())
            {
                throw std::runtime_error(rMsg + " message is required");
            }
        }
        return _payload;
    }
}