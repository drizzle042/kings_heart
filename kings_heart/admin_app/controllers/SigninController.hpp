#pragma once

#include <drogon/HttpController.h>


class SigninController : public drogon::HttpController<SigninController>
{
  public:
    METHOD_LIST_BEGIN

    ADD_METHOD_TO(SigninController::signin, "/api/v1/admin/signin", drogon::Post);

    METHOD_LIST_END
    
    void signin(
      const drogon::HttpRequestPtr& request, 
      std::function<void (const drogon::HttpResponsePtr &)>&& responder
    ) const;
};
