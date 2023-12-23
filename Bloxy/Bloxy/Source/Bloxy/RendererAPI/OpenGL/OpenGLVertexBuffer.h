#pragma once
#include "Renderer/VertexBuffer.h"


namespace Bloxy
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(uint32_t size);
		virtual ~OpenGLVertexBuffer() override;

		virtual void Bind() override;
	protected:
		virtual void SetRawData(void* data, uint32_t size) override;
	private:
		uint32_t m_RendererID;
	};
}