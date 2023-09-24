#ifndef App_H
#define App_H

#include <memory>
#include <string>


namespace KingsHeart
{
    class App
    {
    private:
        App() =default;

        App(const App&) =delete;
        App& operator = (const App&) =delete;
        
        App(App&&) =delete;
        App& operator = (App&&) =delete;

        static std::shared_ptr<App> _app;
        static void* _mongocxxInstance;

    public:
        static App& init(const std::string& envFileName = ".env");
        void run() const;

        ~App();
    };
}

#endif