#pragma once

Ghost::Application* Ghost::CreateApplication();
int main(int argc, char** argv)
{
    Ghost::Log::Init();
    GHOST_CORE_WARN("Initialized Log!");
    GHOST_CORE_INFO("Hello!");

    auto app = Ghost::CreateApplication();
    app->run();
    delete app;

    return 0;
}
