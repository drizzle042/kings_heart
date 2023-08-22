#include "PayloadBuilder.hpp"


namespace KingsHeart
{
    PayloadBuilder& PayloadBuilder::add_meta_datum(MetaDatum&& metaDatum)
    { 
        this->_payload._metaData.emplace(metaDatum.get_key(), metaDatum);
        return *this;
    }

    PayloadBuilder& PayloadBuilder::add_meta_data(std::vector<MetaDatum>&& metaData)
    {
        for (const MetaDatum& metaDatum : metaData) {
            this->_payload._metaData.emplace(metaDatum.get_key(), metaDatum);
        }
        return *this;
    }


    PayloadBuilder& PayloadBuilder::add_required_meta_datum_key(std::string&& requiredMetaDatumKey)
    { 
        this->_payload._requiredMetaDatumKeys.insert(requiredMetaDatumKey);
        return *this; 
    }

    PayloadBuilder& PayloadBuilder::add_required_meta_datum_keys(std::unordered_set<std::string>&& requiredMetaDatumKeys)
    {
        this->_payload._requiredMetaDatumKeys = std::move(requiredMetaDatumKeys);
        return *this;
    }


    PayloadBuilder& PayloadBuilder::add_message(Message&& msg)
    { 
        this->_payload._messages.emplace(msg.get_key(), msg);
        return *this;
    }

    PayloadBuilder& PayloadBuilder::add_messages(std::vector<Message>&& msgs)
    {
        for (const Message& msg : msgs) {
            this->_payload._messages.emplace(msg.get_key(), msg);
        }
        return *this;
    }


    PayloadBuilder& PayloadBuilder::add_required_message_key(std::string&& requiredMsgKey)
    { 
        this->_payload._requiredMessageKeys.insert(requiredMsgKey);
        return *this;
    }

    PayloadBuilder& PayloadBuilder::add_required_message_keys(std::unordered_set<std::string>&& requiredMsgKeys)
    {
        this->_payload._requiredMessageKeys = std::move(requiredMsgKeys);
        return *this;
    }


    const Payload PayloadBuilder::build() const
    {
        for (const std::string& requiredMetaDatumKey : _payload._requiredMetaDatumKeys) {
            if (this->_payload._metaData.find(requiredMetaDatumKey) == this->_payload._metaData.end())
            {
                throw std::runtime_error(requiredMetaDatumKey + " metaDatum is required");
            }
        }
        for (const std::string& requiredMsgKey : _payload._requiredMessageKeys) {
            if (this->_payload._messages.find(requiredMsgKey) == this->_payload._messages.end())
            {
                throw std::runtime_error(requiredMsgKey + " message is required");
            }
        }
        return _payload;
    }
}