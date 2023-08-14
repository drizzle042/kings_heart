#pragma once

#include <trantor/utils/Logger.h>

namespace KingsHeart
{
    template<typename Arg>
    void Log::trace(const Arg& msg)
    { LOG_TRACE << msg; }
    template<typename Arg, typename... Args>
    void Log::trace(const Arg& msg, const Args&... msgs)
    { 
        LOG_TRACE << msg;
        Log::trace(msgs...);
    }

    template<typename Arg>
    void Log::debug(const Arg& msg)
    { LOG_DEBUG << msg; }
    template<typename Arg, typename... Args>
    void Log::debug(const Arg& msg, const Args&... msgs)
    { 
        LOG_DEBUG << msg;
        Log::debug(msgs...);
    }

    template<typename Arg>
    void Log::info(const Arg& msg)
    { LOG_INFO << msg; }
    template<typename Arg, typename... Args>
    void Log::info(const Arg& msg, const Args&... msgs)
    { 
        LOG_INFO << msg;
        Log::info(msgs...);
    }

    template<typename Arg>
    void Log::warn(const Arg& msg)
    { LOG_WARN << msg; }
    template<typename Arg, typename... Args>
    void Log::warn(const Arg& msg, const Args&... msgs)
    { 
        LOG_WARN << msg;
        Log::warn(msgs...);
    }

    template<typename Arg>
    void Log::error(const Arg& msg)
    { LOG_ERROR << msg; }
    template<typename Arg, typename... Args>
    void Log::error(const Arg& msg, const Args&... msgs)
    { 
        LOG_ERROR << msg;
        Log::error(msgs...);
    }

    template<typename Arg>
    void Log::fatal(const Arg& msg)
    { LOG_FATAL << msg; }
    template<typename Arg, typename... Args>
    void Log::fatal(const Arg& msg, const Args&... msgs)
    { 
        LOG_FATAL << msg;
        Log::fatal(msgs...);
    }
}