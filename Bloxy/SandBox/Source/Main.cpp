#include "pch.h"
#include "Bloxy.h"


class SandBox : public Bloxy::Application
{
public:
	SandBox(const std::vector<std::string>& args)
		:Bloxy::Application(args)
	{

	}
};


Bloxy::Application* Bloxy::Application::Create(const std::vector<std::string>& args)
{
	return new SandBox(args);
}