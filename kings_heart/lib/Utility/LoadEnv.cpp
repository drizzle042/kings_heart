#include "LoadEnv.hpp"

namespace KingsHeart
{
    void LoadEnv::init(const char* filename)
    { LoadEnv::do_init(OptionsNone, filename); }

    void LoadEnv::init(int flags, const char* filename)
    { LoadEnv::do_init(flags, filename); }

    #ifdef _MSC_VER

    // https://stackoverflow.com/questions/17258029/c-setenv-undefined-identifier-in-visual-studio
    int setenv(const char *name, const char *value, int overwrite)
    {
        int errcode = 0;

        if (!overwrite)
        {
            size_t envsize = 0;
            errcode = getenv_s(&envsize, NULL, 0, name);
            if (errcode || envsize) return errcode;
        }
        return _putenv_s(name, value);
    }

    #endif // _MSC_VER

    size_t LoadEnv::find_var_start(const std::string& str, size_t pos, std::string& start_tag)
    {
        size_t p1 = str.find('$',pos);
        size_t p2 = str.find("${",pos);
        size_t pos_var = (std::min)(p1,p2);
        if(pos_var != std::string::npos) start_tag = (pos_var == p2)? "${":"$";
        return pos_var;
    }

    size_t LoadEnv::find_var_end(const std::string& str, size_t pos, const std::string& start_tag)
    {
        char end_tag = (start_tag == "${")? '}':' ';
        size_t pos_end = str.find(end_tag, pos);
        if(pos_end == std::string::npos && end_tag == ' ')
        { pos_end = str.length(); }
        return pos_end;
    }

    void LoadEnv::ltrim(std::string& s) 
    { s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c); })); }

    void LoadEnv::rtrim(std::string& s) 
    { s.erase(std::find_if(s.rbegin(), s.rend(), [](int c) {return !std::isspace(c); }).base(), s.end()); }

    void LoadEnv::trim(std::string& s) 
    {
        ltrim(s);
        rtrim(s);
    }

    std::string LoadEnv::trim_copy(std::string s) 
    {
        trim(s);
        return s;
    }

    std::pair<std::string, bool> LoadEnv::resolve_vars(size_t iline, const std::string& str)
    {
        std::string resolved;

        size_t pos = 0;
        size_t pre_pos = pos;
        size_t nvar = 0;

        bool finished = false;
        while(!finished)
        {
            std::string start_tag;
            pos = find_var_start(str,pos,start_tag);

            if(pos != std::string::npos)
            {
                nvar++;

                size_t pos_start = pos;

                size_t lstart = start_tag.length();
                size_t lend   = (lstart>1)? 1 : 0;

                resolved += str.substr(pre_pos,pos-pre_pos);

                pos = find_var_end(str,pos,start_tag);

                if(pos != std::string::npos)
                {
                    std::string var = str.substr(pos_start,pos-pos_start+1);

                    std::string env_var = var.substr(lstart,var.length()-lstart-lend);

                    rtrim(env_var);

                    if(const char* env_str = std::getenv(env_var.c_str()))
                    {
                        resolved += env_str;
                        nvar--;
                    }
                    else
                    { std::cout << "LoadEnv: Variable " << var << " is not defined on line " << iline << std::endl; }

                    pre_pos = pos+lend;
                }
            }
            else 
            { finished = true; }
        }

        if(pre_pos < str.length())
        { resolved += str.substr(pre_pos); }

        return std::make_pair(resolved,(nvar == 0));
    }

    void LoadEnv::do_init(int flags, const char* filename)
    {
        std::ifstream file;
        std::string line;

        file.open(filename);

        if (file)
        {
            unsigned int i = 1;

            while (getline(file, line))
            {
                const auto pos = line.find("=");

                if (pos != std::string::npos)
                {
                    auto name = trim_copy(line.substr(0, pos));
                    auto line_stripped = strip_quotes(trim_copy(line.substr(pos + 1)));

                    auto p = resolve_vars(i,line_stripped);
                    bool ok = p.second;

                    if(ok) 
                    {
                        const auto& val = p.first;
                        setenv(name.c_str(), val.c_str(), ~flags & LoadEnv::Preserve);
                    }
                }
                ++i;
            }
        }
    }

    std::string LoadEnv::strip_quotes(const std::string& str)
    {
        const std::size_t len = str.length();

        if (len < 2)
        { return str; }

        const char first = str[0];
        const char last = str[len - 1];

        if (first == last && ('"' == first || '\'' == first))
        { return str.substr(1, len - 2); }

        return str;
    }

}