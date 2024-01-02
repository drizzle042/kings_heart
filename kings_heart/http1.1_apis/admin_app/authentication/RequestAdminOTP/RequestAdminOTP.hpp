#ifndef __RequestAdminOTP_H__
#define __RequestAdminOTP_H__

#include <future>
#include <drogon/HttpController.h>
#include <drogon/HttpTypes.h>
#include <drogon/utils/FunctionTraits.h>
#include "AdminBagit.hpp"
#include "GenericBagit.hpp"
#include "HttpInput.hpp"
#include "HttpOutput.hpp"
#include "GenerateAdminOTP.hpp"


namespace KingsHeart
{
  class RequestAdminOTP : public drogon::HttpController<RequestAdminOTP, false>
  {
  public:
    METHOD_LIST_BEGIN
      ADD_METHOD_TO(
        RequestAdminOTP::send_OTP, 
        "/api/v1/admin/request-otp", 
        drogon::Post
      );
    METHOD_LIST_END
    
    void send_OTP(const drogon::HttpRequestPtr&, drogon::AdviceCallback&&) const;
  };
}

#endif