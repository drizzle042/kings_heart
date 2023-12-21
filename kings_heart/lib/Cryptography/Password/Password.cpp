#include "Password.hpp"


namespace KingsHeart
{
    extern std::unordered_map<std::string, HASH_ALGORITHM> STR_TO_HASH_ALGORITHM;
    extern std::string PASSWORD_ALGORITHM;

    Password::Password(const std::string& input)
    {
        size_t pos = 0;
        std::string algorithm;
        if ((pos = input.find("$")) != std::string::npos)
            algorithm = input.substr(0, pos);

        static std::string passwordAlgo = get_env_var(PASSWORD_ALGORITHM, false);
        if (algorithm.empty())
            algorithm = passwordAlgo;

        this->__set_state(
            algorithm.empty() ? 
            HASH_ALGORITHM::SCRYPT : 
            STR_TO_HASH_ALGORITHM[algorithm], 
            input
        );
    }

    Password::operator std::string()
    { return std::string(*this->__state); }

    bool Password::operator==(const std::string& rhs)
    { return *this->__state == rhs; }

    bool Password::operator==(const KDFunction& rhs)
    { return *this->__state == rhs; }

    bool Password::operator!=(const std::string& rhs)
    { return *this->__state != rhs; }

    bool Password::operator!=(const KDFunction& rhs)
    { return *this->__state != rhs; }

    void Password::__set_state(HASH_ALGORITHM algorithm, const std::string& input)
    {
        std::unordered_map<HASH_ALGORITHM, std::function<std::shared_ptr<KDFunction>(const std::string&)>> HASH_ALGORITHM_TO_ALGO_PTR
        {
            { HASH_ALGORITHM::SCRYPT, [](const std::string& input){ return std::make_shared<Scrypt>(input); } }
        };
        this->__state = HASH_ALGORITHM_TO_ALGO_PTR[algorithm](input);
    }
}