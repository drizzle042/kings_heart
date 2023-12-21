#ifndef __FileRegistry_H__
#define __FileRegistry_H__

#include <memory>
#include <unordered_map>
#include <utility>
#include <string>
#include "File.hpp"


namespace KingsHeart
{
    class FileRegistry
    {
    public:
        static void add_file(const std::string&, File&&);
        static void remove_file(const std::string&);
        static const File& get_file(const std::string& key) noexcept(false);

    private:
        FileRegistry() =delete;
        static std::unordered_map<std::string, File> _registry;
    };
}

#endif