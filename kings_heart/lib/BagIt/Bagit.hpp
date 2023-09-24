#ifndef Bagit_H
#define Bagit_H

#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>


namespace KingsHeart
{
    class MetaDatum 
    {
    private:
        std::string _metaDatum;

    public:
        explicit MetaDatum(const std::string&);
        const bool operator == (const MetaDatum&) const;
        operator std::string () const;
        const std::string& read() const;
    };

    class Message 
    {
    private:
        std::string _msg;

    public:
        explicit Message(const std::string&);
        const bool operator == (const Message&) const;
        operator std::string () const;
        const std::string& read() const;
    };

    class PayloadBuilder;

    class Payload
    {
    private:
        Payload() =default;
        friend class PayloadBuilder;
        std::unordered_map<std::string, MetaDatum> _metaData;
        std::unordered_map<std::string, Message> _messages;

    public:
        const bool operator == (const Payload&) const;

        const MetaDatum* get_meta_datum(const std::string&) const;
        const std::unordered_map<std::string, MetaDatum>& get_meta_data() const;

        const Message* get_message(const std::string&) const;
        const std::unordered_map<std::string, Message>& get_messages() const;
    };

    class PayloadBuilder
    {
    private:
        Payload _payload;
        std::vector<std::string> _requiredMetaData;
        std::vector<std::string> _requiredMessages;
        
    public:
        PayloadBuilder& add_meta_datum(const std::string&, const MetaDatum&);
        PayloadBuilder& add_required_meta_data(const std::vector<std::string>&);

        PayloadBuilder& add_message(const std::string&, const Message&);
        PayloadBuilder& add_required_messages(const std::vector<std::string>&);

        const Payload& build() const;
    };
}

#endif