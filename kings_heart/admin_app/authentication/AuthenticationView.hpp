#ifndef AuthenticationView_H
#define AuthenticationView_H

#include <drogon/HttpController.h>
#include <drogon/HttpTypes.h>
#include <drogon/utils/FunctionTraits.h>
#include "HttpInput.hpp"
#include "AuthenticationController.hpp"
#include "HttpOutput.hpp"


namespace KingsHeart
{
  class SigninView : public drogon::HttpController<SigninView, false>
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
}

#endif