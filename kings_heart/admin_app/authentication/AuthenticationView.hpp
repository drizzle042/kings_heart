#pragma once

#include <drogon/HttpTypes.h>
#include <drogon/HttpController.h>
#include <drogon/utils/FunctionTraits.h>
#include "HttpInput.hpp"
#include "AuthenticationController.hpp"
#include "AbstractHttpOutput.hpp"


class SigninView : public drogon::HttpController<SigninView>
{
  public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(SigninView::signin, "/api/v1/admin/signin", drogon::Post);
    METHOD_LIST_END
    
    void signin(
      const drogon::HttpRequestPtr&,
      std::function<void (const drogon::HttpResponsePtr &)>&&
    ) const;
};