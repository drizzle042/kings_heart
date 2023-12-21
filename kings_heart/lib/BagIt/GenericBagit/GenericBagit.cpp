#include "GenericBagit.hpp"


namespace KingsHeart
{
    void to_json(nlohmann::json& output, const Generic_Output& input)
    { output = nlohmann::json { {"status", input.status}, {"message", input.message} }; }

    void from_json(const nlohmann::json& input, Generic_Output& output)
    {
        auto status = input.find("status");
        output.status = (status != input.end() && !(status->is_null())) ? *status : "";

        auto message = input.find("message");
        output.message = (message != input.end() && !(message->is_null())) ? *message : "";
    }
}