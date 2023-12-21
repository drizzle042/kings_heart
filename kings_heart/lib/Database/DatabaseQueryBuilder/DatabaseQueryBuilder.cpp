#include "DatabaseQueryBuilder.hpp"
#include <iostream>


namespace KingsHeart
{
    DatabaseQueryBuilder::DatabaseQueryBuilder(const nlohmann::json& queryParam)
    : __queryParams{&queryParam} {}

    DatabaseQuery DatabaseQueryBuilder::operator()() const
    {
        std::vector<uint8_t> bytes = nlohmann::json::to_bson(*this->__queryParams);
        bsoncxx::document::view view{bytes.data(), bytes.size()};
        return DatabaseQuery{view};
    }
}