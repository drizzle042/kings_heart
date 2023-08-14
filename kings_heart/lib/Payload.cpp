#include "Payload.hpp"


namespace KingsHeart
{
    PayloadBuilder& PayloadBuilder::add_header(Header&& header)
    { 
        this->_payload._headers.emplace(header.get_key(), header);
        return *this;
    }

    PayloadBuilder& PayloadBuilder::add_headers(std::vector<Header>&& headers)
    {
        for (const Header& header : headers) {
            this->_payload._headers.emplace(header.get_key(), header);
        }
        return *this;
    }


    PayloadBuilder& PayloadBuilder::add_required_header_key(std::string&& requiredHeaderKey)
    { 
        this->_payload._requiredHeaderKeys.insert(requiredHeaderKey);
        return *this; 
    }

    PayloadBuilder& PayloadBuilder::add_required_header_keys(std::unordered_set<std::string>&& requiredHeaderKeys)
    {
        this->_payload._requiredHeaderKeys = std::move(requiredHeaderKeys);
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
        for (const std::string& requiredHeaderKey : _payload._requiredHeaderKeys) {
            if (this->_payload._headers.find(requiredHeaderKey) == this->_payload._headers.end())
            {
                throw std::runtime_error(requiredHeaderKey + " header is required");
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


    const Header* Payload::find_header_by_key(const std::string& key) const
    {
        auto it = this->_headers.find(key);
        return (it != this->_headers.end()) ? &it->second : nullptr;
    }

    const Header* Payload::find_header_by_value(const std::string& value) const
    {
        for (const auto& pair : this->_headers)
        {
            if (pair.second.get_value() == value) {
                return &pair.second;
            }
        }
        return nullptr;
    }

    const std::unordered_set<const Header*> Payload::get_headers() const
    {
        std::unordered_set<const Header*> headers;
        for (auto& pair : this->_headers)
        {
            headers.insert(&pair.second);
        }
        return headers;
    }


    const Message* Payload::find_message_by_key(const std::string& key) const
    {
        auto it = this->_messages.find(key);
        return (it != this->_messages.end()) ? &it->second : nullptr;
    }

    const Message* Payload::find_message_by_value(const std::string& value) const
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
}