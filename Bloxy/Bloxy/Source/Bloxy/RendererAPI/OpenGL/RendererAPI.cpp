#include "pchBloxy.h"
#include "RendererAPI.h"


namespace Bloxy
{
	RendererAPI* RendererAPI::s_Instance = nullptr;
	RendererAPI::RendererAPI()
		:m_Backend(Backend::None)
	{

	}

	void RendererAPI::Init(Backend backend)
	{
		s_Instance = new RendererAPI();
		s_Instance->m_Backend = backend;
	}

	void RendererAPI::Destroy()
	{
		delete s_Instance;
	}

	RendererAPI::Backend RendererAPI::GetBackend()
	{
		return s_Instance->m_Backend;
	}
}