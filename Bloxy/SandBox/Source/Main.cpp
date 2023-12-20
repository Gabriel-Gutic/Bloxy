#include "pch.h"
#include "Bloxy.h"


class SandBoxLayer : public Bloxy::Layer
{
public:
	SandBoxLayer()
	{

	}

	virtual void OnUpdate() override
	{
		Bloxy::Application::GetWindow()->SetTitle(std::to_string(Bloxy::Time::GetFPS()));
	

	}
};


class SandBox : public Bloxy::Application
{
public:
	SandBox(const std::vector<std::string>& args)
		:Bloxy::Application(args)
	{
		AddLayer("SandBoxLayer", new SandBoxLayer());
	}
};


Bloxy::Application* Bloxy::Application::Create(const std::vector<std::string>& args)
{
	return new SandBox(args);
}