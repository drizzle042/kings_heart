#pragma once

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
        FileRegistry() =default;
        static std::unordered_map<std::string, File> _registry;

    public:
        static void add_file(File&&);
        static void add_file(File&&, std::string&&);
        static void remove_file(const std::string&);
        static File& get_file(const std::string& key);
    };
}