#ifndef __GenericBagit_H__
#define __GenericBagit_H__

#include <string>
#include <nlohmann/json.hpp>


namespace KingsHeart
{
    struct Generic_Output 
    {
        std::string status;
        std::string message;
    };

    void to_json(nlohmann::json& output, const Generic_Output& input);
    void from_json(const nlohmann::json& input, Generic_Output& output);
}

#endif