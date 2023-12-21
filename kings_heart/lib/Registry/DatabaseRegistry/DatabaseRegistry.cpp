#include "DatabaseRegistry.hpp"


namespace KingsHeart
{
    DatabaseInstance DatabaseRegistry::_DB{};

    extern std::string MAIN_DATABASE_SERVER_URI;

    DatabaseClientPool& DatabaseRegistry::get_database_pool(){
        static std::string mainServerURI = get_env_var(MAIN_DATABASE_SERVER_URI);
        static DatabaseURI mainURI{mainServerURI};
        static DatabaseClientPool mainPool{mainURI};
        return mainPool;
    };
}