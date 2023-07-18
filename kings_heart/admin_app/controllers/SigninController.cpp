#include <kings_heart/admin_app/controllers/SigninController.hpp>


void SigninController::signin(
    const drogon::HttpRequestPtr& request, 
    std::function<void (const drogon::HttpResponsePtr &)>&& responder
) const
{
    Json::Value data;
    data["accessToken"] = "s_u_c_c_e_s_s";

    Json::Value payload;
    payload["status"] = "success";
    payload["data"] = data;

    drogon::HttpResponsePtr response{drogon::HttpResponse::newHttpJsonResponse(payload)};
    responder(response);
};