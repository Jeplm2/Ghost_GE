#include <Ghost.h>

class ExampleLayer : public Ghost::Layer
{
    public:
        ExampleLayer()
            : Layer("Example")
        {

        }

        void OnUpdate() override
        {
            LOG("ExampleLayer::Update");
        }

        void OnEvent(Ghost::Event& event) override
        {
            LOG(event);
        }
};

class Sandbox : public Ghost::Application
{
    public:
        Sandbox()
        {
            PushLayer(new ExampleLayer());
        }

        ~Sandbox()
        {
        }

};

Ghost::Application* Ghost::CreateApplication()
{
    return new Sandbox();
}