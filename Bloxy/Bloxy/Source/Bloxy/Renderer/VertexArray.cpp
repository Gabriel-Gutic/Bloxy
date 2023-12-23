#include "pchBloxy.h"
#include "VertexArray.h"


namespace Bloxy
{
    std::shared_ptr<VertexBuffer> VertexArray::GetVertexBuffer() const
    {
        return m_VertexBuffer;
    }

    std::shared_ptr<IndexBuffer> VertexArray::GetIndexBuffer() const
    {
        return m_IndexBuffer;
    }
}
