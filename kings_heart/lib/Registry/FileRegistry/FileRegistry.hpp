#ifndef FileRegistry_H
#define FileRegistry_H

#include <memory>
#include <unordered_map>
#include <utility>
#include <string>
#include "File.hpp"


namespace KingsHeart
{
    class FileRegistry
    {
    private:
        FileRegistry() =delete;
        static std::unordered_map<std::string, File> _registry;

    public:
        static void add_file(File&&);
        static void remove_file(const std::string&);
        static const File& get_file(const std::string& key) noexcept(false);
    };
}

#endif