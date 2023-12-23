#include "pchBloxy.h"
#include "OpenGLShaderProgram.h"

#include "OpenGLShader.h"

#include <glad/glad.h>


namespace Bloxy
{
	OpenGLShaderProgram::OpenGLShaderProgram(std::string_view vertexShader, std::string_view fragmentShader)
		:m_RendererID(0)
	{
		std::shared_ptr<OpenGLShader> _vertexShader = std::make_shared<OpenGLShader>(vertexShader, ShaderType::Vertex);
		m_VertexShader = _vertexShader;
		std::shared_ptr<OpenGLShader> _fragmentShader = std::make_shared<OpenGLShader>(fragmentShader, ShaderType::Fragment);
		m_FragmentShader = _fragmentShader;

		m_RendererID = glCreateProgram();
		glAttachShader(m_RendererID, _vertexShader->Get());
		glAttachShader(m_RendererID, _fragmentShader->Get());
		glLinkProgram(m_RendererID);
	}

	OpenGLShaderProgram::~OpenGLShaderProgram()
	{
		glDeleteProgram(m_RendererID);
	}

	void OpenGLShaderProgram::Use()
	{
		glUseProgram(m_RendererID);
	}
}