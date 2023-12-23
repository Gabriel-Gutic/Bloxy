#pragma once
#include "Renderer/VertexArray.h"
#include "OpenGLBufferLayout.h"


namespace Bloxy
{
	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray(const OpenGLBufferLayout& layout, uint32_t vertexBufferSize, uint32_t indexBufferSize);
		virtual ~OpenGLVertexArray() override;

		virtual void Bind() override;
	private:
		uint32_t m_RendererID;
	};
}