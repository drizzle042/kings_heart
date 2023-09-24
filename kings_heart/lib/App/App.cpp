#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include "App.hpp"
#include "LoadEnv.hpp"
#include "DatabaseRegistry.hpp"
#include "MainLog.hpp"
#include "AuthenticationView.hpp"


namespace KingsHeart
{
    std::shared_ptr<App> App::_app;
    void* App::_mongocxxInstance = nullptr;
    
    App& App::init(const std::string& envFileName)
    {
        if (App::_app == nullptr)
        {
            LoadEnv::init(envFileName.c_str());

            spdlog::flush_on(spdlog::level::level_enum::info);

            extern std::string get_env_var(const std::string& var) noexcept(false);
            extern std::string MAIN_LOGGER;

            auto mainLogger = spdlog::stdout_color_mt(get_env_var(MAIN_LOGGER));
            mainLogger->set_pattern("[%c] %v");
            mainLogger->set_level(spdlog::level::level_enum::trace);

            extern std::string COMMAND_STORAGE_LOGGER;
            extern std::string COMMAND_STORAGE_LOGGER_PATH;
            extern std::string COMMAND_STORAGE_LOGGER_MAX_FILE_SIZE;
            extern std::string COMMAND_STORAGE_LOGGER_MAX_ALLOWED_FILES;

            auto commandStorageLogger = spdlog::rotating_logger_mt(
                get_env_var(COMMAND_STORAGE_LOGGER),
                get_env_var(COMMAND_STORAGE_LOGGER_PATH),
                std::stoi(get_env_var(COMMAND_STORAGE_LOGGER_MAX_FILE_SIZE)),
                std::stoi(get_env_var(COMMAND_STORAGE_LOGGER_MAX_ALLOWED_FILES)));
            commandStorageLogger->set_pattern("%v [%c]");
            commandStorageLogger->set_level(spdlog::level::level_enum::info);

            App::_mongocxxInstance = new DatabaseInstance;

            DatabaseURI databaseUri;
            DatabaseClient databaseClient{databaseUri};

            extern std::string MAIN_DATABASE;

            Database mainDatabase = databaseClient.database(get_env_var(MAIN_DATABASE));
            DatabaseRegistry::add_database(MAIN_DATABASE, std::move(mainDatabase));

            App::_app = std::shared_ptr<App>{new App};
        }

        return *App::_app;
    };

    void App::run() const
    {
        drogon::app()
                .registerController<SigninView>(std::make_shared<SigninView>())
                .addListener("0.0.0.0", 8000)
                .run();
    }

    App::~App()
    {
        delete reinterpret_cast<DatabaseInstance*>(App::_mongocxxInstance);
        spdlog::drop_all();
    }
}