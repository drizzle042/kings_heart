#ifndef __HttpInput_T__
#define __HttpInput_T__


namespace KingsHeart
{
    template<typename T>
    HttpInput<T>::HttpInput(const HttpRequest& request)
    : _request{request} {}

    template<typename T>
    const T& HttpInput<T>::operator()()
    {
        if (this->_request->getHeader("Content-Type") == "application/cbor")
        { 
            nlohmann::json input = nlohmann::json::from_cbor(this->_request->body(), true, false);
            for (const auto& i : this->_request->getParameters()) { input[i.first] = i.second; }
            this->_input = input.template get<T>();
            return this->_input;
        }

        if (this->_request->getHeader("Content-Type") == "application/json")
        { 
            nlohmann::json input = nlohmann::json::parse(this->_request->body(), nullptr, false);
            for (const auto& i : this->_request->getParameters()) { input[i.first] = i.second; }
            this->_input = input.template get<T>();
            return this->_input; 
        }

        return this->_input;
    }

    template<typename T>
    HTTP_OUTPUT HttpInput<T>::get_output_type()
    {
        if (this->_request->getHeader("Accept") == "application/cbor")
        { return HTTP_OUTPUT::CBOR; }

        if (this->_request->getHeader("Accept") == "application/json")
        { return HTTP_OUTPUT::JSON; }

        if (this->_request->getHeader("Accept") == "text/html")
        { return HTTP_OUTPUT::HTML; }

        return HTTP_OUTPUT::CBOR;
    }
}

#endif