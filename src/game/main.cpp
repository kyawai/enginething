#include <iostream>
#include <memory>


#include <engine/Application.h>
#include <engine/Component.h>
#include <engine/Entity.h>
//#include <engine/Exception.h>
#include <engine/Renderer.h>


int main()
{
	std::shared_ptr<Application> app = Application::Initialize();
	std::shared_ptr<Entity> ent = app->AddEntity();
	//std::shared_ptr<Component> comp = ent->addComponent();
	std::shared_ptr<Renderer> rend = ent->addComponent<Renderer>();

	app->Run();
	std::cout << "game RUnning" << std::endl;
	
return 0;
}