#pragma once


namespace Bloxy
{
	class Layer
	{
	public:
		virtual void OnUpdate(){}
		virtual void OnWindowClose(){}
		virtual void OnWindowMinimize(){}
		virtual void OnWindowMaximize(){}
		virtual void OnWindowResize(int width, int height){}
	};
}