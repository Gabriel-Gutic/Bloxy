#include "pchBloxy.h"
#include "Renderer.h"

#include "RendererAPI/RendererAPI.h"
#include "RendererAPI/OpenGL/OpenGLRenderer.h"


namespace Bloxy
{
    Renderer* Renderer::s_Instance = nullptr;

    Renderer::Renderer()
        :m_VertexArray(nullptr)
    {
    }

    Renderer::~Renderer()
    {
        
    }

    Renderer* Renderer::Get()
    {
        return s_Instance;
    }

    void Renderer::Init()
    {
        BLOXY_ASSERT(!s_Instance, "Renderer already initialized!");

        switch (RendererAPI::GetBackend())
        {
        case RendererAPI::Backend::OpenGL:
            s_Instance = new (std::nothrow) OpenGLRenderer();
        }
        BLOXY_ASSERT(s_Instance, "Failed to initialize Renderer!");
    }

    void Renderer::Destroy()
    {
        delete s_Instance;
    }

    void Renderer::DrawQuad()
    {
        s_Instance->_DrawQuad();
    }
}
