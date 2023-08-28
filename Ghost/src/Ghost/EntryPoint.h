#pragma once


// #ifdef GHOST_PLATFORM_LINUX

/*extern*/ Ghost::Application* Ghost::CreateApplication();
int main(int argc, char** argv)
{
    auto app = Ghost::CreateApplication();
    app->run();
    delete app;

    return 0;
}


// #endif