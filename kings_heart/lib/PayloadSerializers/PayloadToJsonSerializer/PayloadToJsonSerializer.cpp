#include "PayloadToJsonSerializer.hpp"

namespace KingsHeart
{
    std::string PayloadToJsonSerializer::serialize(const Payload& payload)
    {
        if (this->_jsonString == nullptr)
        {
            this->_payload = std::make_shared<Payload>(payload);

            Json::Value json;
            Json::Value metaData;
            Json::Value messages;
            Json::Value requiredMetaDatumKeys;
            Json::Value requiredMsgKeys;

            for (auto metaDatum : payload.get_meta_data())
            { metaData[metaDatum->get_key()] = metaDatum->get_value(); }

            for (auto msg : payload.get_messages())
            { messages[msg->get_key()] = msg->get_value(); }

            for (const std::string& metaDatumKey : payload.get_required_meta_datum_keys())
            { requiredMetaDatumKeys.append(metaDatumKey); }

            for (const std::string& msgKey : payload.get_required_message_keys())
            { requiredMsgKeys.append(msgKey); }

            json["metaData"] = metaData;
            json["messages"] = messages;
            json["required_meta_datum_keys"] = requiredMetaDatumKeys;
            json["required_message_keys"] = requiredMsgKeys;

            Json::FastWriter fastWriter;
            this->_jsonString = std::make_shared<std::string>(fastWriter.write(json));
        }
        return *this->_jsonString;
    }

    Payload PayloadToJsonSerializer::deserialize(const std::string& jsonString)
    {
        if (this->_payload == nullptr)
        {
            this->_jsonString = std::make_shared<std::string>(jsonString);

            Json::Value json;
            Json::Reader reader;

            bool isUsable = reader.parse(jsonString, json);
            if (!isUsable){ throw std::runtime_error("Cannot parse this json string input!"); }

            Json::Value metaData = json["metaData"];
            for (const auto& key : metaData.getMemberNames())
            { this->_payloadBuilder.add_meta_datum(MetaDatum(key, metaData[key].asString())); }

            Json::Value messages = json["messages"];
            for (const auto& key : messages.getMemberNames())
            { this->_payloadBuilder.add_message(Message(key, metaData[key].asString())); }

            Json::Value requiredMetaDatumKeys = json["required_meta_datum_keys"];
            for (auto key : requiredMetaDatumKeys.getMemberNames())
            { this->_payloadBuilder.add_required_meta_datum_key(std::move(key)); }

            Json::Value requiredMsgKeys = json["required_message_keys"];
            for (auto key : requiredMsgKeys.getMemberNames())
            { this->_payloadBuilder.add_required_message_key(std::move(key)); }

            this->_payload = std::make_shared<Payload>(this->_payloadBuilder.build());
        }
        return *this->_payload;
    }

    void PayloadToJsonSerializer::clear()
    {
        this->_jsonString = nullptr;
        this->_payload = nullptr;
    }
}