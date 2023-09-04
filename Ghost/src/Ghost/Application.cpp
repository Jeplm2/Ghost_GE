#include <gpch.h>
#include <Ghost/Application.h>

#include <Ghost/Log.h>

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

    void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
    }

    void Application::PushOverLay(Layer* layer)
    {
        m_LayerStack.PushOverLay(layer);
    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispather(e);
        dispather.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

        // LOG(e);

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
        {
            (*--it)->OnEvent(e);
            if (e.Handled)
                break;
        }
    }


    void Application::Run()
    {
        while (m_Running)
        {
            glClearColor(0.1f,0.1f,0.3f,1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            for (Layer* layer : m_LayerStack)
                layer->OnUpdate();

            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return true;
    }
}