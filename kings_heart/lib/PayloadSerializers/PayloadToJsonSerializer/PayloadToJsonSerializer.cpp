#include "PayloadToJsonSerializer.hpp"
#include <iostream>

namespace KingsHeart
{
    std::string PayloadToJsonSerializer::serialize(const Payload& payload)
    {
        Json::Value json;
        Json::Value metaData;
        Json::Value messages;

        for (auto& metaDatum : payload.get_meta_data())
        { metaData[metaDatum.first] = metaDatum.second.read(); }

        for (auto& msg : payload.get_messages())
        { messages[msg.first] = msg.second.read(); }

        json["metaData"] = metaData;
        json["messages"] = messages;

        Json::FastWriter _fastWriter;
        std::string _s(_fastWriter.write(json));
        if (_s.back() == '\n') _s.pop_back();

        return std::move(_s);
    }

    Payload PayloadToJsonSerializer::deserialize(const std::string& jsonString)
    {
        Json::Value json;
        Json::Reader reader;

        bool isUsable = reader.parse(jsonString, json);
        if (!isUsable){ throw std::runtime_error("Cannot parse this json string input!"); }

        PayloadBuilder _payloadBuilder;

        Json::Value metaData = json["metaData"];
        for (auto& key : metaData.getMemberNames())
        { _payloadBuilder.add_meta_datum(key, MetaDatum{metaData[key].asString()}); }

        Json::Value messages = json["messages"];
        for (auto& key : messages.getMemberNames())
        { _payloadBuilder.add_message(key, Message{messages[key].asString()}); }
            
        return _payloadBuilder.build();
    }
}