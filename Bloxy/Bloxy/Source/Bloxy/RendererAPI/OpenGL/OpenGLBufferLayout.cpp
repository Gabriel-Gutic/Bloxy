#include "pchBloxy.h"
#include "OpenGLBufferLayout.h"

#include <glad/glad.h>


namespace Bloxy
{
	void OpenGLBufferLayout::PushFloat(uint32_t count)
	{
		m_Elements.push_back(OpenGLBufferElement(count, GL_FLOAT));
	}

	void OpenGLBufferLayout::PushInt(uint32_t count)
	{
		m_Elements.push_back(OpenGLBufferElement(count, GL_INT));
	}

	void OpenGLBufferLayout::PushUInt(uint32_t count)
	{
		m_Elements.push_back(OpenGLBufferElement(count, GL_UNSIGNED_INT));
	}

	const std::vector<OpenGLBufferElement>& OpenGLBufferLayout::GetElements() const
	{
		return m_Elements;
	}
}

