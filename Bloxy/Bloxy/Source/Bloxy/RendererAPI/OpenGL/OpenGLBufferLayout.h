#pragma once


namespace Bloxy
{
	struct OpenGLBufferElement
	{
		uint32_t Count;
		uint32_t Type;

		OpenGLBufferElement(uint32_t count, uint32_t type)
			:Count(count), Type(type){}
	};

	class OpenGLBufferLayout
	{
	public:
		OpenGLBufferLayout(){}

		void PushFloat(uint32_t count);
		void PushInt(uint32_t count);
		void PushUInt(uint32_t count);

		const std::vector<OpenGLBufferElement>& GetElements() const;
	private:
		std::vector<OpenGLBufferElement> m_Elements;
	};
}