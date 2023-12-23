#include "pchBloxy.h"
#include "OpenGLVertexBuffer.h"

#include <glad/glad.h>


namespace Bloxy
{
	OpenGLVertexBuffer::OpenGLVertexBuffer(uint32_t size)
		:m_RendererID(0)
	{
		glCreateBuffers(1, &m_RendererID);
		Bind();

		glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &m_RendererID);
	}

	void OpenGLVertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	}

	void OpenGLVertexBuffer::SetRawData(void* data, uint32_t size)
	{
		Bind();
		glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
	}
}