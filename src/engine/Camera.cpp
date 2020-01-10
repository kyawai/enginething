#include "Camera.h"

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 1020
Camera::~Camera()
{
}

void Camera::CamIni(float _angle)
{
		angle = _angle;
		pos = glm::vec3(1.0f);
}

glm::mat4 Camera::getView()
{
		return view;
}

glm::mat4 Camera::getProjection()
{
		projection = glm::perspective(glm::radians(angle), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 100.0f);
		return projection;
}

glm::mat4 Camera::GetView()
{
	return view;
}

glm::mat4 Camera::GetModel()
{
	model = glm::mat4(1.0f);
	model = glm::translate(model, pos);
	view = glm::inverse(model);
	return model;
}

void Camera::onTick()
{
	std::shared_ptr<Entity> ent = getEntity();
	std::shared_ptr<Transform> tran = ent->getComponent<Transform>();



	SDL_Event event = { 0 };
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			quit = true;
		}
		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_a:
				tran->AddPos(glm::vec3(-0.2f, 0, 0));
				//SetPos(glm::vec3(-0.2f, 0, 0));
				break;
			case SDLK_d:
				tran->AddPos(glm::vec3(0.2f, 0, 0));
				//SetPos(glm::vec3(0.2f, 0, 0));
				break;
			case SDLK_w:
				tran->AddPos(glm::vec3(0, 0.2f, 0));
				//SetPos(glm::vec3(0, 0.2f, 0));
				break;
			case SDLK_s:
				tran->AddPos(glm::vec3(0, -0.2f, 0));
				//SetPos(glm::vec3(0, -0.2f, 0));
				break;
			case SDLK_f:
				//SetPos(glm::vec3(0, 0, -0.2f));
				break;
			case SDLK_g:
				//SetPos(glm::vec3(0, 0, 0.2f));
				break;

			}
		}
	}
	GetModel();
}
