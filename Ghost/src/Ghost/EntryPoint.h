#pragma once

Ghost::Application* Ghost::CreateApplication();
int main(int argc, char** argv)
{
    Ghost::Log::Init();
    Ghost::Log::GetCoreLogger()->warn("Initialized Log!");
    Ghost::Log::GetClientLogger()->warn("Hello!");

    auto app = Ghost::CreateApplication();
    app->run();
    delete app;

    return 0;
}
