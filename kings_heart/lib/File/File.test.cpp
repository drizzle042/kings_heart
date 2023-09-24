#include <fstream>
#include <gtest/gtest.h>
#include "File.hpp"


namespace KingsHeart
{
    class FileTest : public testing::Test
    {
    protected:
        static void SetUpTestSuite()
        {
            std::ofstream testFile{"test1.txt"};
            testFile << "The quick brown fox.";
            testFile.close();
        };

    public:
        std::string _fileContent{"The quick brown fox."};
        File _file{"test1.txt"};
    };

    TEST_F(FileTest, FileEquality)
    { EXPECT_TRUE(_file == File{"test1.txt"}); }

    TEST_F(FileTest, GetFileName)
    { EXPECT_TRUE(_file.get_file_name() == "test1.txt"); }

    TEST_F(FileTest, GetTextContent)
    { EXPECT_TRUE(_file.get_text_content() == _fileContent); }
}