#include "DatabaseRegistry.hpp"


namespace KingsHeart
{
    DatabaseInstance DatabaseRegistry::_DB{};

    DatabaseClientPool& DatabaseRegistry::get_database_pool(){
        static DatabaseURI mainURI{get_env_t().MAIN_DATABASE_SERVER_URI};
        static DatabaseClientPool mainPool{mainURI};
        return mainPool;
    };
}