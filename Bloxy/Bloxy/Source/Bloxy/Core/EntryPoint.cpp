#include "pchBloxy.h"

#include "RendererAPI/RendererAPI.h"
#include "Application.h"
#include "Printing/Logger.h"


int main(int argc, char** argv)
{
    Bloxy::Logger::Init();

    Bloxy::RendererAPI::Init(Bloxy::RendererAPI::Backend::OpenGL);

    std::vector<std::string> args(argc);
    args.reserve(argc);

    for (int i = 0; i < argc; i++)
    {
        args[i] = argv[i];
    }

    auto app = Bloxy::Application::Create(args);

    app->Run();

    delete app;

    Bloxy::RendererAPI::Destroy();

    return 0;
}