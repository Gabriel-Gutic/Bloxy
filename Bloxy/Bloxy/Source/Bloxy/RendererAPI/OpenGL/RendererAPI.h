#pragma once


namespace Bloxy
{
	class RendererAPI
	{
		RendererAPI();
	public:
		enum class Backend
		{
			None = 0,
			OpenGL = 1,
		};

		static void Init(Backend backend);
		static void Destroy();
		static Backend GetBackend();
	private:
		Backend m_Backend;

		static RendererAPI* s_Instance;
	};
}
