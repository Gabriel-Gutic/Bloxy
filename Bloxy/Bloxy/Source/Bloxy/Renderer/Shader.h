#pragma once


namespace Bloxy
{
	enum class ShaderType
	{
		None = 0,
		Vertex = 1,
		Fragment = 2,
	};

	class Shader
	{
	public:
		Shader() = default;
		virtual ~Shader() = default;
	};
}