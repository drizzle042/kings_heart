namespace KingsHeart
{
	extern std::string MAIN_DATABASE;
	extern std::string MAIN_DATABASE_ADMIN_COLLECTION;

    template<typename T>
	GetAdminCommand<T>::GetAdminCommand()
	: GetAdminCommand<T>({}) {}

    template<typename T>
    GetAdminCommand<T>::GetAdminCommand(const nlohmann::json& query)
    : __query{&query}
	{
		static std::string mainDb = get_env_var(MAIN_DATABASE);
		static std::string mainDbAdminTable = get_env_var(MAIN_DATABASE_ADMIN_COLLECTION);
		static DatabaseInfo dbInfo{mainDb, mainDbAdminTable};

	    this->__node = std::make_shared<LiveDatabaseNode<T>>(dbInfo);
    }

    template<typename T>
	const T& GetAdminCommand<T>::operator()()
	{
        this->__output = this->__node->fetch_one(*this->__query);
		return this->__output;
	}
}