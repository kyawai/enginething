#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "Exception.h"
#include "Component.h"
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <exception>


class Renderer : public Component
{
	SDL_Window *window;
	GLuint programId;
	GLuint vaoId;

public:

	Renderer();
	~Renderer();
	virtual void onTick();
	void Renderer::onDisplay();
};

#endif