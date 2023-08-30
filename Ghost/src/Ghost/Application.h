#pragma once

#include <Ghost/Core.h>
#include <Ghost/Events/Event.h>


namespace Ghost
{
    class Application
    {
        public:
            Application();
            virtual ~Application();

            void run();
    };

    Application* CreateApplication();
}