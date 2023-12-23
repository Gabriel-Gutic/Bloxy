#pragma once
#include "VertexArray.h"
#include "ShaderProgram.h"


namespace Bloxy
{
	class Renderer
	{
	protected:
		Renderer();
	public:
		Renderer(const Renderer& other) = delete;
		virtual ~Renderer();

		static Renderer* Get();
		void Init();
		void Destroy();

		virtual void Begin() = 0;
		virtual void End() = 0;

		static void DrawQuad();
	protected:
		virtual void Flush() = 0;

		virtual void _DrawQuad() = 0;
	protected:
		std::unique_ptr<VertexArray> m_VertexArray;
		std::unique_ptr<ShaderProgram> m_ShaderProgram;

		static Renderer* s_Instance;
	};
}
