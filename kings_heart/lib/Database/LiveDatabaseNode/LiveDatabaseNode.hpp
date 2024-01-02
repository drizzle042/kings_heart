#ifndef __LiveDatabaseNode_H__
#define __LiveDatabaseNode_H__

#include <string>
#include <unordered_map>
#include <vector>
#include "bson.hpp"
#include <nlohmann/json.hpp>
#include "DatabaseNode.hpp"
#include "DatabaseRegistry.hpp"
#include "DatabaseQueryBuilder.hpp"

#include <any>
#include <fstream>
#include <iostream>
#include <chrono>


namespace KingsHeart
{
    template<typename T>
    class LiveDatabaseNode : public DatabaseNode<T>
    {
    public:
        explicit LiveDatabaseNode(const DatabaseInfo&);
        
        T fetch_one() const override;
        T fetch_one(const nlohmann::json&) const override;
        std::vector<T> fetch_many() const override;
        std::vector<T> fetch_many(const nlohmann::json&) const override;

    private:
        LiveDatabaseNode() =delete;
        DatabaseInfo __dbInfo;
        DatabaseClientPtr __clientPtr = DatabaseRegistry::get_database_pool().acquire();
    };
}

#include "LiveDatabaseNode.tpp"

#endif