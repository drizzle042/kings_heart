#include "DatabaseRegistry.hpp"

namespace KingsHeart
{
    std::unordered_map<std::string, Database> DatabaseRegistry::_registry;

    void DatabaseRegistry::add_database(const std::string& key, Database&& database)
    { _registry.emplace(key, std::move(database)); }

    void DatabaseRegistry::remove_database(const std::string& key)
    { _registry.erase(key); }

    const Database& DatabaseRegistry::get_database(const std::string& key)
    {
        auto it = DatabaseRegistry::_registry.find(key);

        if (it != DatabaseRegistry::_registry.end())
        { return it->second; }
        
        throw std::runtime_error(key + " not found in the Database Registry!");
    }
}