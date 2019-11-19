#include <iostream>
#include "Application.h"


std::shared_ptr<Application> Application::Initialize()
{
	std::shared_ptr<Application> ini = std::make_shared<Application>();
	ini->self = ini;
	return ini;
}

std::shared_ptr<Entity> Application::AddEntity()
{
	std::shared_ptr<Entity> ent = std::make_shared<Entity>();
	entities.push_back(ent);
	ent->self = ent;
	return ent;
}

void Application::Run()
{
	while (true)
	{
		for (std::vector<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
		{
			(*it)->tick();
			std::cout << "entity tick" << std::endl;
		}
		for (std::vector<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
		{
			(*it)->display();
			std::cout << "entities display" << std::endl;
		}
	}

}

void Application::Stop()
{
	running = false;
}
