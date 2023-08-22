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

    File::File(File&& movedFile)
    : _filename{std::move(movedFile._filename)},
    _textContent{std::move(movedFile._textContent)}
    {
        movedFile._fileStream.close();
        this->_fileStream.open(this->_filename);
        if (!this->_fileStream.is_open())
        {throw std::runtime_error("Could not use " + this->_filename + " as a valid file");}
    }

    File& File::operator = (File&& movedFile)
    {
        this->_filename = std::move(movedFile._filename);
        this->_textContent = std::move(movedFile._textContent);

        movedFile._fileStream.close();
        this->_fileStream.open(this->_filename);
        if (!this->_fileStream.is_open())
        {throw std::runtime_error("Could not use " + this->_filename + " as a valid file");}

        return *this;
    }


    const std::string& File::get_file_name()
    { return this->_filename; }

    const std::string& File::get_file_name() const
    { return this->_filename; }


    const std::string& File::get_content()
    {
        if (this->_textContent == nullptr)
        {
            std::istreambuf_iterator<char> begin(this->_fileStream), end;            
            std::string textData(begin, end);
            this->_textContent = std::make_shared<std::string>(textData);
        }
        return *this->_textContent;
    }


    File::~File()
    { this->_fileStream.close(); }
}