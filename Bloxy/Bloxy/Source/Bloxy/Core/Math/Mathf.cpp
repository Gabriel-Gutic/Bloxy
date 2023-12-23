#include "pchBloxy.h"
#include "Mathf.h"


namespace Bloxy
{
	Mat4 Mathf::Translate(Vector3 position)
	{
		Mat4 M(1.0f);
		M = glm::translate(M, position);
		return M;
	}

	Mat4 Mathf::Scale(Vector3 scale)
	{
		Mat4 M(1.0f);
		M = glm::scale(M, scale);
		return M;
	}

	Mat4 Mathf::Rotate(float radians, Vector3 axis)
	{
		Mat4 M(1.0f);
		M = glm::rotate(M, radians, axis);
		return M;
	}
}


