#include "AuthenticationController.hpp"
#include "MainLog.hpp"


namespace KingsHeart
{
    SigninCommand::SigninCommand(const Payload& payload)
    : _payload{std::shared_ptr<Payload>{const_cast<Payload*>(&payload)}} {}

    Payload SigninCommand::execute()
    {
        MainLog::trace("Admin Signin called...");

        const Message* email = this->_payload->get_message("email");
        const Message* password = this->_payload->get_message("password");

        JsonWebToken token{std::unordered_map<std::string, std::string>{
            {"email", email->read()}
        }};

        extern std::string MAIN_DATABASE;
        Database db = DatabaseRegistry::get_database(MAIN_DATABASE);

        extern std::string MAIN_DATABASE_ADMIN_COLLECTION;
        auto user = db.collection(MAIN_DATABASE_ADMIN_COLLECTION).find_one({});
        std::string str_usr = bsoncxx::to_json(user.value());
        MainLog::trace(str_usr);

        return PayloadBuilder{}.add_message("status", Message{"success"})
                               .add_message("token", Message{token.get_token()})
                               .add_message("data", Message{str_usr})
                               .build();
    }
}