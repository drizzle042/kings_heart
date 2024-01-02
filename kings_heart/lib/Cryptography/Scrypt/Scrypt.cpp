#include "Scrypt.hpp"


namespace KingsHeart
{
    extern std::unordered_map<HASH_ALGORITHM, std::string> HASH_ALGORITHM_TO_STR;

    Scrypt::Scrypt(const std::string& input)
    {
        std::vector<std::string> vec = split(input, "$");

        if (vec.size() == 7) this->__build(vec);
        else this->__make(input);
    }

    Scrypt::operator std::string()
    {
        return std::format(
            "{}${}${}${}${}${}${}",
            HASH_ALGORITHM_TO_STR[this->_algorithm],
            this->__blockSize,
            this->__memory,
            this->__parallelism,
            this->__cipherLength,
            this->__salt,
            this->__cipher
        );
    }

    bool Scrypt::operator==(const std::string& rhs)
    { return this->__cipher == this->__generate_cipher(rhs); }

    bool Scrypt::operator==(const KDFunction& rhs)
    {
        const Scrypt* castRhs = static_cast<const Scrypt*>(&rhs);
        if (castRhs) return this->__cipher == castRhs->__cipher;
        return false;
    }

    bool Scrypt::operator!=(const std::string& rhs)
    { return this->__cipher != this->__generate_cipher(rhs); }

    bool Scrypt::operator!=(const KDFunction& rhs)
    {
        const Scrypt* castRhs = static_cast<const Scrypt*>(&rhs);
        if (castRhs) return this->__cipher != castRhs->__cipher;
        return true;
    }

    void Scrypt::__build(const std::vector<std::string>& input)
    {
        this->__blockSize       = stoi(input[1]);
        this->__memory          = stoi(input[2]);
        this->__parallelism     = stoi(input[3]);
        this->__cipherLength    = stoi(input[4]);
        this->__salt            = input[5];
        this->__cipher          = input[6];
    }

    void Scrypt::__make(const std::string& input)
    {
            static std::random_device randomDevice;
            static std::uniform_int_distribution<unsigned short int> distribution{4, 8};
        
            this->__blockSize       = 8;
            this->__memory          = 1024;
            this->__parallelism     = 2;
            this->__cipherLength    = distribution(randomDevice);
            this->__salt            = generate_salt();
            this->__cipher          = this->__generate_cipher(input);
    }

    std::string Scrypt::__generate_cipher(const std::string& input)
    {
        unsigned char buffer[1 << this->__cipherLength];
        
        CryptoPP::Scrypt{}.DeriveKey(
            buffer,
            sizeof(buffer),
            reinterpret_cast<const unsigned char*>(input.data()),
            input.size(),
            reinterpret_cast<unsigned char*>(this->__salt.data()),
            this->__salt.size(),
            this->__memory,
            this->__blockSize,
            this->__parallelism
        );

        std::string cipher;
        CryptoPP::Base64Encoder cipherEncoder{new CryptoPP::StringSink{cipher}};
        cipherEncoder.Put(buffer, sizeof(buffer));
        cipherEncoder.MessageEnd();

        return cipher;
    }
}