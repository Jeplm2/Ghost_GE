#pragma once

// #include "./Core.h"

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