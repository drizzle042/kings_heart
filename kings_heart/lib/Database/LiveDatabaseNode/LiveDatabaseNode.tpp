namespace KingsHeart
{
	template<typename T>
	LiveDatabaseNode<T>::LiveDatabaseNode(const DatabaseInfo& dbInfo)
	: __dbInfo{dbInfo} {}
		
	template<typename T>
	T LiveDatabaseNode<T>::fetch_one() const
	{ return this->fetch_one({}); }

	template<typename T>
	T LiveDatabaseNode<T>::fetch_one(const nlohmann::json& queryParams) const
	{
		DatabaseQueryBuilder Query{queryParams};

		auto result = this->__clientPtr
					  ->database(this->__dbInfo.database)
					  .collection(this->__dbInfo.databaseStore)
					  .find_one(Query());

		T payload;
		if (result) payload = nlohmann::json::from_bson(
								result->data(), 
								result->data() + result->length()
							);
		
		return payload;
	}

	template<typename T>
	std::vector<T> LiveDatabaseNode<T>::fetch_many() const
	{ return this->fetch_many({}); }

	template<typename T>
	std::vector<T> LiveDatabaseNode<T>::fetch_many(const nlohmann::json& queryParams) const
	{
		DatabaseQueryBuilder Query{queryParams};

		auto results = this->__clientPtr
						   ->database(this->__dbInfo.database)
						   .collection(this->__dbInfo.databaseStore)
						   .find(Query());

		std::vector<T> payloads;

		payloads.reserve(std::distance(results.begin(), results.end()));
		for (auto& result : results)
		{
			T payload = nlohmann::json::from_bson(result.data(), result.data() + result.length());
			payloads.push_back(std::move(payload));
		}

		return payloads;
	}
}