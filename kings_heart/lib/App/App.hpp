#ifndef __App_H__
#define __App_H__

#include <memory>
#include <string>


namespace KingsHeart
{
    class App
    {
    public:
        static App& init();
        static App& init(const std::string&);
        
        void run() const;

        ~App();

    private:
        App();

        App(const App&) =delete;
        App& operator=(const App&) =delete;
        
        App(App&&) =delete;
        App& operator=(App&&) =delete;

        static std::shared_ptr<App> _app;
    };
}

#endif