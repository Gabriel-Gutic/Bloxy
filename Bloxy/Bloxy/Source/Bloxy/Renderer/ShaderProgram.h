#pragma once
#include "Shader.h"


namespace Bloxy
{
	class ShaderProgram
	{
	public:
		ShaderProgram();
		virtual ~ShaderProgram() = default;

		virtual void Use() = 0;
	protected:
		std::shared_ptr<Shader> m_VertexShader;
		std::shared_ptr<Shader> m_FragmentShader;
	};
}