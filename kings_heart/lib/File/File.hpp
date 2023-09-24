#ifndef File_H
#define File_H

#include <memory>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

namespace KingsHeart
{
    class File
    {
    private:
        File() =delete;
        std::string _filename;
        std::fstream _fileStream;
        std::shared_ptr<std::string> _textContent;
        std::shared_ptr<std::vector<char>> _binaryContent;

    public:
        explicit File(const std::string&);

        const bool operator == (const File&) const;
        
        const std::string& get_file_name() const;

        const std::string& get_text_content();
        const std::vector<char>& get_binary_content();
    };
}

#endif