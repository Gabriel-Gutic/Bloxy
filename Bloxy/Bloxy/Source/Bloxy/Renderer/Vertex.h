#pragma once


namespace Bloxy
{
	struct Vertex
	{
		Vector3 Position;
		Vector4 Color;

		Vertex(const Vector3& position = Vector3(0.0f), const Vector4& color = Vector4(1.0f))
			:Position(position),
			Color(color)
		{
		}
	};
}