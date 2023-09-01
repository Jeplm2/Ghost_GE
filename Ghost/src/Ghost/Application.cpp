#include <Ghost/Application.h>
#include <Ghost/Events/ApplicationEvent.h>

#include <GLFW/glfw3.h>


namespace Ghost
{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }

    Application::~Application()
    {
        
    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispather(e);
        dispather.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

        // LOG(e);
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

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return true;
    }
}