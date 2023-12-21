#ifndef __DatabaseRegistry_H__
#define __DatabaseRegistry_H__

#include <string>
#include "Functions.hpp"
#include "DatabaseNode.hpp"


namespace KingsHeart
{
    class DatabaseRegistry
    {
    public:
        static DatabaseClientPool& get_database_pool();

    private:
        DatabaseRegistry() =delete;
        static DatabaseInstance _DB;
    };
}

#endif