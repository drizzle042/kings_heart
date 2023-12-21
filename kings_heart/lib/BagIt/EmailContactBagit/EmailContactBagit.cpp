#include "EmailContactBagit.hpp"


namespace KingsHeart
{
    void to_json(nlohmann::json& output, const EmailContact& input)
    { output = nlohmann::json{ {"name", input.name}, {"email", input.email} }; }

    void from_json(const nlohmann::json& input, EmailContact& output)
    {
        auto name = input.find("name");
        output.name = (name != input.end() && !(name->is_null())) ? *name : "";

        auto email = input.find("email");
        output.email = (email != input.end() && !(email->is_null())) ? *email : "";
    }
}