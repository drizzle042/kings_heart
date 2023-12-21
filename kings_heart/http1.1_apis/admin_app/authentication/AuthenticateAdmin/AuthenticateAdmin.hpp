#ifndef __AuthenticateAdmin_H__
#define __AuthenticateAdmin_H__

#include <drogon/HttpController.h>
#include <drogon/HttpTypes.h>
#include <drogon/utils/FunctionTraits.h>
#include "HttpInput.hpp"
#include "HttpOutput.hpp"
#include "GenerateAdminToken.hpp"


namespace KingsHeart
{
  class AuthenticateAdmin : public drogon::HttpController<AuthenticateAdmin, false>
  {
  public:
    METHOD_LIST_BEGIN
      ADD_METHOD_TO(
        AuthenticateAdmin::generate_auth, 
        "/api/v1/admin/signin", 
        drogon::Post
      );
    METHOD_LIST_END
    
    void generate_auth(const drogon::HttpRequestPtr&, drogon::AdviceCallback&&) const;
  };
}

#endif