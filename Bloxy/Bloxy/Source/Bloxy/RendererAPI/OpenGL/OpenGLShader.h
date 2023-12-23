#pragma once
#include "Renderer/Shader.h"


namespace Bloxy
{
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(std::string_view filepath, ShaderType type);
		virtual ~OpenGLShader() override;

		uint32_t Get();
	private:
		uint32_t m_RendererID;
	};
}