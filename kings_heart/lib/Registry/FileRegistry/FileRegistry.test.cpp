#include <fstream>
#include <gtest/gtest.h>
#include "FileRegistry.hpp"


namespace KingsHeart
{
    class FileRegistryTest : public testing::Test
    {
    protected:
        static void SetUpTestSuite()
        {
            std::ofstream _testFile{"test2.txt"};
            _testFile << "The quick brown fox.";
            _testFile.close();
            FileRegistry::add_file("test2.txt", File{"test2.txt"});
        };
    };

    TEST_F(FileRegistryTest, GetFile)
    { EXPECT_TRUE(FileRegistry::get_file("test2.txt") == File{"test2.txt"}); }

    TEST_F(FileRegistryTest, RemoveFile)
    {
        FileRegistry::get_file("test2.txt");
        FileRegistry::remove_file("test2.txt");
        EXPECT_THROW(
            try {FileRegistry::get_file("test2.txt");}
            catch (const std::runtime_error& e)
            {
                EXPECT_TRUE(std::string(e.what()) == "test2.txt not found in the File Registry!");
                throw;
            }, 
            std::runtime_error
        );
    }
}