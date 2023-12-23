#pragma once
#include "Vector.h"


namespace Bloxy
{
	class Mathf
	{
		Mathf(){}
	public:
		static Mat4 Translate(Vector3 position);
		static Mat4 Scale(Vector3 scale);
		static Mat4 Rotate(float radians, Vector3 axis);
	};
}
