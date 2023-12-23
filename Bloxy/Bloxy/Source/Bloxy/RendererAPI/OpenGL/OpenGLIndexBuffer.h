#pragma once
#include "Renderer/IndexBuffer.h"


namespace Bloxy
{
	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t size);
		virtual ~OpenGLIndexBuffer() override;

		virtual void Bind() override;
	protected:
		virtual void SetRawData(uint32_t* data, uint32_t size) override;
	private:
		uint32_t m_RendererID;
	};
}