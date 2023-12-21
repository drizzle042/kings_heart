#include "FileRegistry.hpp"


namespace KingsHeart
{
    std::unordered_map<std::string, File> FileRegistry::_registry;

    void FileRegistry::add_file(const std::string& key, File&& file)
    { FileRegistry::_registry.emplace(key, std::move(file)); }

    void FileRegistry::remove_file(const std::string& key)
    { FileRegistry::_registry.erase(key); }

    const File& FileRegistry::get_file(const std::string& key)
    {
        auto it = FileRegistry::_registry.find(key);

        if (it != FileRegistry::_registry.end()) 
        { return it->second; } 
        
        throw std::runtime_error(key + " not found in the File Registry!");
    }
}