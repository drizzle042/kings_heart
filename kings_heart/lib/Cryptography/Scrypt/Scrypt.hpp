#ifndef __Scrypt_H__
#define __Scrypt_H__

#include <string>
#include <format>
#include <vector>
#include <random>
#include <cryptopp/scrypt.h>
#include <cryptopp/base64.h>
#include "Functions.hpp"
#include "Enums.hpp"
#include "KeyDerivation.hpp"


namespace KingsHeart
{
    class Scrypt : public KDFunction
    {
    public:
        explicit Scrypt(const std::string&);
        operator std::string() override;
        bool operator==(const std::string&) override;
        bool operator==(const KDFunction&) override;
        bool operator!=(const std::string&) override;
        bool operator!=(const KDFunction&) override;

    private:
        HASH_ALGORITHM _algorithm = HASH_ALGORITHM::SCRYPT;
        unsigned short int __blockSize;
        unsigned short int __memory;
        unsigned short int __parallelism;
        unsigned short int __cipherLength;
        std::string __salt;
        std::string __cipher;
    
    private:
        Scrypt() =delete;
        void __build(const std::vector<std::string>&);
        void __make(const std::string&);
        std::string __generate_cipher(const std::string&);
    };
}

#endif