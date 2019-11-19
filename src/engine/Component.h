#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <memory>
#include "Entity.h"
class Application;
class Entity;


class Component
{
	friend Entity;

	std::weak_ptr<Entity> entity;

public:
	std::shared_ptr<Entity> getEntity();
	//std::shared_ptr<Application> getApp;
	virtual void onInit();
	virtual void onBegin();
	virtual void onTick();
	virtual void onDisplay();
	std::shared_ptr<Application> getApp();

};



#endif // ! _COMPONENTS_H_
