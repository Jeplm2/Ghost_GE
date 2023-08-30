#pragma once


Ghost::Application* Ghost::CreateApplication();
int main(int argc, char** argv)
{
    Ghost::Log log("Ghost GE");


    auto app = Ghost::CreateApplication();
    app->run();
    delete app;

    return 0;
}
