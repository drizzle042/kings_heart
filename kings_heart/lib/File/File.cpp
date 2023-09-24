#include "File.hpp"


namespace KingsHeart
{
    File::File(const std::string& fname)
    : _filename{fname}
    {
        this->_fileStream.open(this->_filename);
        if (!this->_fileStream.is_open())
        {throw std::runtime_error("Could not use " + this->_filename + " as a valid file");}
    }
    
    const bool File::operator == (const File& file) const
    { return this->_filename == file._filename; }

    const std::string& File::get_file_name() const
    { return this->_filename; }


    const std::string& File::get_text_content()
    {
        if (!this->_textContent)
        {
            std::istreambuf_iterator<char> begin(this->_fileStream), end;
            this->_textContent = std::make_shared<std::string>(begin, end);
        }
        return *this->_textContent;
    }

    const std::vector<char>& File::get_binary_content()
    {
        if (!this->_binaryContent)
        {
            this->_fileStream.close();
            this->_fileStream.open(this->_filename, std::fstream::binary);

            std::istreambuf_iterator<char> begin(this->_fileStream), end;
            this->_binaryContent = std::make_shared<std::vector<char>>(begin, end);

            this->_fileStream.close();
            this->_fileStream.open(this->_filename);
        }
        return *this->_binaryContent;
    }
}