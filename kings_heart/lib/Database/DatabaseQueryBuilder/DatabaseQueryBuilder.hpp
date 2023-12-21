#ifndef __DatabaseQueryBuilder_H__
#define __DatabaseQueryBuilder_H__

#include <string>
#include <nlohmann/json.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <bsoncxx/json.hpp>


namespace KingsHeart
{
    using DatabaseQuery = bsoncxx::document::value;

    class DatabaseQueryBuilder
    {
    public:
        explicit DatabaseQueryBuilder(const nlohmann::json&);
        DatabaseQuery operator()() const;

    private:
        const nlohmann::json* __queryParams;
    };
}

#endif