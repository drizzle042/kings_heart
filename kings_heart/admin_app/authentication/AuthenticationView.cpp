#include "AuthenticationView.hpp"

using namespace KingsHeart;

void SigninView::signin(
    const drogon::HttpRequestPtr& request,
    std::function<void (const drogon::HttpResponsePtr&)>&& responder
) const
{
    Payload req = HttpInput{request}
                    .add_required_message_keys({"email", "password"})
                    .get_input();

    Payload resp = SigninCommand{req}.execute();

    responder(AbstractHttpOutput{resp}.get_output());
};