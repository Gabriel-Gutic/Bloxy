#pragma once
#include "Renderer/ShaderProgram.h"


namespace Bloxy
{
	class OpenGLShaderProgram : public ShaderProgram
	{
	public:
		OpenGLShaderProgram(std::string_view vertexShader, std::string_view fragmentShader);
		virtual ~OpenGLShaderProgram() override;

		virtual void Use() override;
	private:
		uint32_t m_RendererID;
	};
}