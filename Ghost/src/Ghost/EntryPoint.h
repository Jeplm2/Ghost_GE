#pragma once


Ghost::Application* Ghost::CreateApplication();
int main(int argc, char** argv)
{
    LOG("Ghost GE");


    auto app = Ghost::CreateApplication();
    app->Run();
    delete app;

    return 0;
}
