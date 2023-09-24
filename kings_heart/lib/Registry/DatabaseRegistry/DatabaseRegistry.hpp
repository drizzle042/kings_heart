#ifndef DatabaseRegistry_H
#define DatabaseRegistry_H

#include <memory>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/database.hpp>

namespace KingsHeart
{
    using DatabaseInstance = mongocxx::instance;
    using DatabaseURI = mongocxx::uri;
    using DatabaseClient = mongocxx::client;
    using Database = mongocxx::database;
    
    class DatabaseRegistry
    {
    private:
        DatabaseRegistry() =delete;
        static std::unordered_map<std::string, Database> _registry;

    public:
        static void add_database(const std::string&, Database&&);
        static void remove_database(const std::string&);
        static const Database& get_database(const std::string&) noexcept(false);
    };
}

#endif