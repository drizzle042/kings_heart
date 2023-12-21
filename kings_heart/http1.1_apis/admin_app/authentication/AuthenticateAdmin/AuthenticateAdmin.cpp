#include "AuthenticateAdmin.hpp"


namespace KingsHeart
{
    void AuthenticateAdmin::generate_auth(
        const drogon::HttpRequestPtr& request,
        std::function<void (const drogon::HttpResponsePtr&)>&& responder) const
    {
        HttpInput<AdminAuth_Input> Input{request};
        GenerateAdminTokenCommand GenToken{Input()};
        HttpOutput<AdminAuth_Output> Output{GenToken(), Input.get_output_type()};

        responder(Output());
    };
}