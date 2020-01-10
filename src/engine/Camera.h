#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Component.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/vec3.hpp>
#include "SDL2/SDL.h"
#include <GL/glew.h>
#include <glm/glm.hpp>
class Camera : public Component
{
		glm::vec3 pos;
		glm::mat4 view;
		glm::mat4 projection;
		glm::mat4 model;
		float angle;
		bool quit = false;

public:
		~Camera();
		void CamIni(float _angle);
		glm::mat4 getView();
		glm::mat4 getProjection();
		glm::vec3 GetPos();
		glm::mat4 GetView(); 
		void Camera::onTick();
		glm::mat4 GetModel();
		void SetPos(glm::vec3 _pos);
};

#endif

