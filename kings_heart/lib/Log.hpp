namespace KingsHeart
{
    class Log
    {
    public:
        Log() =default;
        ~Log() =default;

        template<typename Arg>
        static void trace(const Arg&);
        template<typename Arg, typename... Args>
        static void trace(const Arg&, const Args&...);

        template<typename Arg>
        static void debug(const Arg&);
        template<typename Arg, typename... Args>
        static void debug(const Arg&, const Args&...);

        template<typename Arg>
        static void info(const Arg&);
        template<typename Arg, typename... Args>
        static void info(const Arg&, const Args&...);

        template<typename Arg>
        static void warn(const Arg&);
        template<typename Arg, typename... Args>
        static void warn(const Arg&, const Args&...);

        template<typename Arg>
        static void error(const Arg&);
        template<typename Arg, typename... Args>
        static void error(const Arg&, const Args&...);

        template<typename Arg>
        static void fatal(const Arg&);
        template<typename Arg, typename... Args>
        static void fatal(const Arg&, const Args&...);
    };
}

#include "Log.tpp"