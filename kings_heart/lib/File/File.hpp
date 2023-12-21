#ifndef __File_H__
#define __File_H__

#include <memory>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

namespace KingsHeart
{
    class File
    {
    public:
        explicit File(const std::string&);

        bool operator==(const File&) const;        
        const std::string& get_file_name() const;
        operator const std::string&() const;

    private:
        File() =delete;
        std::string _filename;
        std::fstream _fileStream;
        std::string _content;
    };
}

#endif