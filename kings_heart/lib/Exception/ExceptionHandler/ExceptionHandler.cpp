#include "ExceptionHandler.hpp"


namespace KingsHeart
{
    void ExceptionHandler::operator()(
            const std::exception& exception,
            const drogon::HttpRequestPtr& request,
            drogon::AdviceCallback&& responder
    )
    {
        HTTP_OUTPUT outputFomat;

        if (const std::string& acceptHeader = request->getHeader("Accept"); acceptHeader == "application/cbor") 
            outputFomat = HTTP_OUTPUT::CBOR;
        else if (acceptHeader == "application/json") outputFomat = HTTP_OUTPUT::JSON;
        else if (acceptHeader == "text/html") outputFomat = HTTP_OUTPUT::HTML;

        Generic_Output payload{"error", exception.what()};

        HttpResponse response;
        HttpOutput<Generic_Output> Output{payload, outputFomat};

        response = Output();
        std::string message = std::format(
            "[{}] [{}] [{}]",
            request->getMethodString(),
            request->getPath(),
            exception.what()
        );

        extern std::unordered_map<EXCEPTION_LEVEL, std::function<void(const std::string&)>> LOG_EXCEPTION;

        const BaseException* customException = dynamic_cast<const BaseException*>(&exception);

        if (customException != nullptr)
        {
            response->setStatusCode((drogon::HttpStatusCode)customException->get_error_code());
            LOG_EXCEPTION[customException->get_level()](message);
        }
        else
        {
            response->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);
            LOG_EXCEPTION[EXCEPTION_LEVEL::CRITICAL](message);
        }
        
        responder(response);
    }
}