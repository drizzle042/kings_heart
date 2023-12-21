#ifndef __DatabaseNode_H__
#define __DatabaseNode_H__

#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/pool.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/database.hpp>
#include <mongocxx/collection.hpp>


namespace KingsHeart
{
    using DatabaseInstance = mongocxx::instance;
    using DatabaseURI = mongocxx::uri;
    using DatabaseClientPool = mongocxx::pool;
    using DatabaseClient = mongocxx::client;
    using DatabaseClientPtr = mongocxx::pool::entry;
    using Database = mongocxx::database;
    using DatabaseStore = mongocxx::collection;


    struct DatabaseInfo { std::string database, databaseStore; };
    

    template<typename T>
    class DatabaseNode
    {
    public:
        virtual T fetch_one() const =0;
        virtual T fetch_one(const nlohmann::json&) const =0;
        virtual std::vector<T> fetch_many() const =0;
        virtual std::vector<T> fetch_many(const nlohmann::json&) const =0;
        
        // virtual DatabasePayload insert(const std::unordered_map<std::string, std::string>&) const =0;
        // virtual DatabasePayload update(const std::unordered_map<std::string, std::string>&) const =0;
        // virtual DatabasePayload remove(const std::unordered_map<std::string, std::string>&) const =0;
    };
}

#endif