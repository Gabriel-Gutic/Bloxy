#pragma once
#include "VertexBuffer.h"
#include "IndexBuffer.h"


namespace Bloxy
{
	class VertexArray
	{
	public:
		VertexArray(){}
		virtual ~VertexArray() = default;

		virtual void Bind() = 0;

		std::shared_ptr<VertexBuffer> GetVertexBuffer() const;
		std::shared_ptr<IndexBuffer> GetIndexBuffer() const;
	protected:
		std::shared_ptr<VertexBuffer> m_VertexBuffer;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
	};
}