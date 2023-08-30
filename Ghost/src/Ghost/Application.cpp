#include <Ghost/Application.h>
#include <Ghost/Events/ApplicationEvent.h>

#include <GLFW/glfw3.h>


namespace Ghost
{
    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application()
    {
        
    }

    void Application::run()
    {



        while (m_Running)
        {
            glClearColor(0.1f,0.1f,0.3f,1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
    }
}