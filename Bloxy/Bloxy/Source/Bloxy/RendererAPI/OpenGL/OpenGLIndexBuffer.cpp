#include "pchBloxy.h"
#include "OpenGLIndexBuffer.h"

#include <glad/glad.h>


namespace Bloxy
{
	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t size)
		:m_RendererID(0)
	{
		glCreateBuffers(1, &m_RendererID);
		Bind();

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &m_RendererID);
	}

	void OpenGLIndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	}

	void OpenGLIndexBuffer::SetRawData(uint32_t* data, uint32_t size)
	{
		Bind();
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, size, data);
	}
}