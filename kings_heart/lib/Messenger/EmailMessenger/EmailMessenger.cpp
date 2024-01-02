#include "EmailMessenger.hpp"


namespace KingsHeart
{
    EmailMessenger::EmailMessenger(
        std::vector<EmailContact>&& receipients, 
        std::string&& subject, std::string&& message
    )
    : EmailMessenger(
        std::move(receipients), 
        std::move(subject), 
        std::move(message),
        nullptr
    ) {}

    EmailMessenger::EmailMessenger(
        std::vector<EmailContact>&& receipients,
        std::string&& subject,
        std::string&& message,
        std::function<void(drogon::ReqResult, const drogon::HttpResponsePtr&)>&& callback
    )
    : __sender{EmailContact{"King's Heart", get_env_t().SERVER_EMAIL}}, __receipients(std::move(receipients)),
      __subject{std::move(subject)}, __message{std::move(message)}, __callback{std::move(callback)} {}

    void EmailMessenger::operator()()
    {
        static drogon::HttpClientPtr client = drogon::HttpClient::newHttpClient(get_env_t().BREVO_EMAIL_API);

        drogon::HttpRequestPtr request = drogon::HttpRequest::newHttpRequest();

        request->addHeader("accept", "application/json");
        request->addHeader("content-type", "application/json");
        request->addHeader("api-key", get_env_t().BREVO_EMAIL_API_KEY);

        nlohmann::json postData = {
            {"sender", this->__sender},
            {"to", this->__receipients},
            {"subject", this->__subject},
            {"htmlContent", this->__message}
        };

        request->setBody(postData.dump());
        request->setMethod(drogon::HttpMethod::Post);

        client->sendRequest(
            request, 
            [this](drogon::ReqResult status, const drogon::HttpResponsePtr& response)
            { if (this->__callback) this->__callback(status, response); }
        );
    }
}