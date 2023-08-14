#include "AuthenticationView.hpp"

using namespace KingsHeart;

void SigninView::signin(
    const drogon::HttpRequestPtr& request,
    std::function<void (const drogon::HttpResponsePtr&)>&& responder
) const
{
    HttpInput input{request};
    input.add_required_message_keys({"email", "password"});

    SigninCommand signinCommand{input.get_input()};
    Payload resp = signinCommand.execute();

    responder(HttpOutput(resp).get_output());
};