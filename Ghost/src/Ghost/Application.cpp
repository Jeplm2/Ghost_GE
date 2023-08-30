#include <Ghost/Application.h>
#include <Ghost/Log.h>

#include <Ghost/Events/ApplicationEvent.h>


namespace Ghost
{
    Application::Application()
    {

    }

    Application::~Application()
    {
        
    }

    void Application::run()
    {
        WindowResizeEvent e(1280, 720);
        if(e.IsInCategory(EventCategoryApplication))
            Ghost::Log log(e.ToString());



        while (true);
    }
}