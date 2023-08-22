#pragma once

#include <memory>
#include <fstream>
#include <string>
#include <vector>
#include <cstddef>
#include <iterator>

namespace KingsHeart
{
    class File
    {
    private:
        std::string _filename;
        std::fstream _fileStream;
        std::shared_ptr<std::string> _textContent;

    public:
        File() =delete;
        File(const std::string&);
        File(const File&) =delete;
        File& operator = (const File&) =delete;
        File(File&&);
        File& operator = (File&&);

        const std::string& get_file_name();
        const std::string& get_file_name() const;

        const std::string& get_content();

        ~File();
    };
}