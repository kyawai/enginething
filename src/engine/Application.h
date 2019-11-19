#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <memory>
#include <vector>
#include <list>
#include "Entity.h"
#include "Component.h"
class Application;
class Entity;

class Application
{
	bool running;
	std::vector<std::shared_ptr<Entity>> entities;
	std::weak_ptr<Application> self;

public:
	static std::shared_ptr<Application> Initialize();
	std::shared_ptr<Entity> AddEntity();
	void Run();
	void Stop();
};

#endif // !_APPLICATION_H_
