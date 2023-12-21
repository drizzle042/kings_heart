#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include "App.hpp"
#include "LoadEnv.hpp"
#include "Functions.hpp"
#include "File.hpp"
#include "FileRegistry.hpp"
#include "ExceptionHandler.hpp"
#include "AuthenticateAdmin.hpp"
#include "RequestAdminOTP.hpp"


namespace KingsHeart
{
    std::shared_ptr<App> App::_app;

    App::App() =default;

    extern std::string MAIN_LOGGER;
    extern std::string COMMAND_STORAGE_LOGGER;
    extern std::string COMMAND_STORAGE_LOGGER_PATH;
    extern std::string COMMAND_STORAGE_LOGGER_MAX_FILE_SIZE;
    extern std::string COMMAND_STORAGE_LOGGER_MAX_ALLOWED_FILES;
    extern std::string DEFAULT_RESPONSE_TEMPLATE;
    extern std::string OTP_EMAIL_TEMPLATE;
    
    App& App::init(){ return App::init(".env"); }

    App& App::init(const std::string& envFileName)
    {
        if (App::_app == nullptr)
        {
            LoadEnv::init(envFileName.c_str());

            spdlog::flush_on(spdlog::level::level_enum::info);

            auto mainLogger = spdlog::stdout_color_mt(get_env_var(MAIN_LOGGER));
            mainLogger->set_pattern("[%c] %v");
            mainLogger->set_level(spdlog::level::level_enum::trace);

            auto commandStorageLogger = spdlog::rotating_logger_mt(
                get_env_var(COMMAND_STORAGE_LOGGER),
                get_env_var(COMMAND_STORAGE_LOGGER_PATH),
                std::stoi(get_env_var(COMMAND_STORAGE_LOGGER_MAX_FILE_SIZE)),
                std::stoi(get_env_var(COMMAND_STORAGE_LOGGER_MAX_ALLOWED_FILES)));
            commandStorageLogger->set_pattern("%v [%c]");
            commandStorageLogger->set_level(spdlog::level::level_enum::info);

            std::string defaultResponseTemplate = get_env_var(DEFAULT_RESPONSE_TEMPLATE);
            FileRegistry::add_file(defaultResponseTemplate, File{defaultResponseTemplate});

            std::string OTPEmailTemplate = get_env_var(OTP_EMAIL_TEMPLATE);
            FileRegistry::add_file(OTPEmailTemplate, File{OTPEmailTemplate});
            
            App::_app = std::shared_ptr<App>{new App};
        }

        return *App::_app;
    };

    void App::run() const
    {
        drogon::app()
                .setExceptionHandler(ExceptionHandler{});
                
        drogon::app()
                .registerController<AuthenticateAdmin>(std::make_shared<AuthenticateAdmin>())
                .registerController<RequestAdminOTP>(std::make_shared<RequestAdminOTP>())
                .disableSession()
                .enableBrotli(true)
                // .enableRelaunchOnError()
                .enableSendfile(true)
                .addListener("0.0.0.0", 8000)
                .setThreadNum(0)
                .run();
    }

    App::~App()
    { spdlog::drop_all(); }
}