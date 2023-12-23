#include "pchBloxy.h"
#include "OpenGLVertexArray.h"

#include "OpenGLVertexBuffer.h"
#include "OpenGLIndexBuffer.h"

#include <glad/glad.h>


namespace Bloxy
{
	OpenGLVertexArray::OpenGLVertexArray(const OpenGLBufferLayout& layout, uint32_t vertexBufferSize, uint32_t indexBufferSize)
		:m_RendererID(0)
	{
		m_VertexBuffer = std::make_shared<OpenGLVertexBuffer>(vertexBufferSize);
		m_IndexBuffer = std::make_shared<OpenGLIndexBuffer>(indexBufferSize);

		glCreateVertexArrays(1, &m_RendererID);
		Bind();
		m_VertexBuffer->Bind();

		int stride = 0;
		for (auto& element : layout.GetElements())
		{
			stride += 4 * element.Count;
		}

		int i = 0;
		int pointer = 0;
		for (auto& element : layout.GetElements())
		{
			glVertexAttribPointer(i, element.Count, element.Type, GL_FALSE, stride, (void*)pointer);
			glEnableVertexAttribArray(i);

			i++;
			pointer += 4 * element.Count;
		}
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind()
	{
		glBindVertexArray(m_RendererID);
	}
}