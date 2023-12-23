#pragma once
#include "Renderer/Renderer.h"


namespace Bloxy
{
	class OpenGLRenderer : public Renderer
	{
	public:
		OpenGLRenderer();
		virtual ~OpenGLRenderer() override;

		virtual void Begin() override;
		virtual void End() override;
	protected:
		virtual void Flush() override;

		virtual void _DrawQuad() override;
	};
}
