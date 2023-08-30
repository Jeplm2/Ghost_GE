#pragma once

#include <Ghost/Core.h>
#include <Ghost/Events/Event.h>
#include <Ghost/Window.h>


namespace Ghost
{
    class Application
    {
        public:
            Application();
            virtual ~Application();

            void run();
        private:
            std::unique_ptr<Window> m_Window;
            bool m_Running = true;
    };

    Application* CreateApplication();
}