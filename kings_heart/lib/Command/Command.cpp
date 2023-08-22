#include "Command.hpp"

namespace KingsHeart
{
    void Command::store(const std::string& commandName, const Payload& payload)
    {
        PayloadToJsonSerializer payloadSerializer;
        CommandStorage::store(commandName + " " + payloadSerializer.serialize(payload));
    }
}