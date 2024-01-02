namespace KingsHeart
{

    template<typename T>
	GetAdminCommand<T>::GetAdminCommand()
	: GetAdminCommand<T>({}) {}

    template<typename T>
    GetAdminCommand<T>::GetAdminCommand(const nlohmann::json& query)
    : __query{&query}
	{
		static DatabaseInfo dbInfo{
			get_env_t().MAIN_DATABASE,
			get_env_t().MAIN_DATABASE_ADMIN_COLLECTION
		};

	    this->__node = std::make_shared<LiveDatabaseNode<T>>(dbInfo);
    }

    template<typename T>
	const T& GetAdminCommand<T>::operator()()
	{
        this->__output = this->__node->fetch_one(*this->__query);
		return this->__output;
	}
}