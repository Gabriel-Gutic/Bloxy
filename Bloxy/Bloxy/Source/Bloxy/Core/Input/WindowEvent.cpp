#include "pchBloxy.h"
#include "WindowEvent.h"


namespace Bloxy
{
    int WindowResizeEvent::GetWidth() const
    {
        return m_Width;
    }

    int WindowResizeEvent::GetHeight() const
    {
        return m_Height;
    }
}
