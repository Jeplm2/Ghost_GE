#pragma once

#include <Ghost/Core.h>
#include <Ghost/Window.h>
#include <Ghost/LayerStack.h>
#include <Ghost/Events/Event.h>
#include <Ghost/Events/ApplicationEvent.h>


namespace Ghost
{
    class GHOST_API Application
    {
        public:
            Application();
            virtual ~Application();

            void Run();

            void OnEvent(Event& e);

            void PushLayer(Layer* layer);
            void PushOverLay(Layer* layer);
        private:
            bool OnWindowClose(WindowCloseEvent& e);

            std::unique_ptr<Window> m_Window;
            bool m_Running = true;
            LayerStack m_LayerStack;
    };

    Application* CreateApplication();
}