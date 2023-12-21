#ifndef __GenerateAdminAuth_M_H__
#define __GenerateAdminAuth_M_H__

#include <memory>
#include <nlohmann/json.hpp>
#include "Functions.hpp"
#include "Command.hpp"
#include "AdminBagit.hpp"
#include "LiveDatabaseNode.hpp"


namespace KingsHeart
{
    template<typename T>
    class GetAdminCommand : public Command<T>
    {
    public:
        explicit GetAdminCommand();
        explicit GetAdminCommand(const nlohmann::json&);
        const T& operator()() override;

    private:
        const nlohmann::json* __query;
        T __output;
        std::shared_ptr<LiveDatabaseNode<T>> __node;
    };
}

#include "GetAdmin.tpp"

#endif