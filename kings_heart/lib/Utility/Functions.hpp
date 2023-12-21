#ifndef __Functions_H__
#define __Functions_H__

#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <random>
#include <inja/inja.hpp>


namespace KingsHeart
{
    std::string get_env_var(const std::string&, bool required = true) noexcept(false);
    inja::Environment env_factory();
    std::vector<std::string> split(const std::string&, const std::string&);
    std::string generate_salt();
}

#endif