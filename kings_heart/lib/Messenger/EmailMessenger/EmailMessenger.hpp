#ifndef __EmailMessenger_H__
#define __EmailMessenger_H__

#include <string>
#include <vector>
#include <functional>
#include <nlohmann/json.hpp>
#include <drogon/HttpClient.h>
#include <drogon/HttpRequest.h>
#include "Functions.hpp"
#include "Messenger.hpp"
#include "EmailContactBagit.hpp"


namespace KingsHeart
{
    class EmailMessenger : public Messenger
    {
    public:
        explicit EmailMessenger(
            std::vector<EmailContact>&&,
            std::string&&,
            std::string&&
        );
        explicit EmailMessenger(
            std::vector<EmailContact>&&,
            std::string&&,
            std::string&&,
            std::function<void(drogon::ReqResult, const drogon::HttpResponsePtr&)>
        );
        void operator()() override;

    private:
        EmailContact __sender;
        std::vector<EmailContact> __receipients;
        std::string __subject;
        std::string __message;
        std::function<void(drogon::ReqResult, const drogon::HttpResponsePtr&)> __callback;
    };
}

#endif