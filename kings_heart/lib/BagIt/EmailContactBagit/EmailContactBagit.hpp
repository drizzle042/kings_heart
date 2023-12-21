#ifndef __EmailContactBagit_H__
#define __EmailContactBagit_H__

#include <string>
#include <nlohmann/json.hpp>


namespace KingsHeart
{
    struct EmailContact
    {
        std::string name;
        std::string email;
    };

    void to_json(nlohmann::json& output, const EmailContact& input);
    void from_json(const nlohmann::json& input, EmailContact& output);
}

#endif