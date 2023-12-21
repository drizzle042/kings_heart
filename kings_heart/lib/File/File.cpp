#include "File.hpp"


namespace KingsHeart
{
    File::File(const std::string& fname)
    : _filename{fname}
    {
        this->_fileStream.open(this->_filename);
        if (!this->_fileStream.is_open())
        {throw std::runtime_error("Could not use " + this->_filename + " as a valid file");}

        std::istreambuf_iterator<char> begin(this->_fileStream), end;
        this->_content = std::string(begin, end);
    }
    
    bool File::operator==(const File& file) const
    { return this->_filename == file._filename; }

    const std::string& File::get_file_name() const
    { return this->_filename; }

    File::operator const std::string&() const
    { return this->_content; }
}