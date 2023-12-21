#ifndef __Password_H__
#define __Password_H__

#include <string>
#include <memory>
#include <functional>
#include "Functions.hpp"
#include "Enums.hpp"
#include "KeyDerivation.hpp"
#include "Scrypt.hpp"


namespace KingsHeart
{
    class Password : public KDFunction
    {
    public:
        explicit Password(const std::string&);
        operator std::string() override;
        bool operator==(const std::string&) override;
        bool operator==(const KDFunction&) override;
        bool operator!=(const std::string&) override;
        bool operator!=(const KDFunction&) override;

    private:
        Password() =delete;
        std::shared_ptr<KDFunction> __state;
        void __set_state(HASH_ALGORITHM, const std::string&);
    };
}

#endif