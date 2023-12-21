#ifndef __LoadEnv_H__
#define __LoadEnv_H__

#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cctype>


namespace KingsHeart
{
    class LoadEnv
    {
    public:
        static const unsigned char Preserve = 1 << 0;
        static const unsigned short OptionsNone = 0;
        static void init(const char* filename = ".env");
        static void init(unsigned short flags, const char* filename = ".env");

    private:
        LoadEnv() = delete;
        
        static void do_init(unsigned short flags, const char*);
        static std::string strip_quotes(const std::string&);

        static std::pair<std::string, bool> resolve_vars(size_t, const std::string&);
        static void ltrim(std::string&);
        static void rtrim(std::string&);
        static void trim(std::string&);
        static std::string trim_copy(std::string);
        static size_t find_var_start(const std::string&, size_t, std::string&);
        static size_t find_var_end(const std::string&, size_t, const std::string&);
    };
}   

#endif