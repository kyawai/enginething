#define STB_IMAGE_IMPLEMENTATION
#include <GL/glew.h>

#include "Renderer.h"
#include "Entity.h"

#include <exception>

#include <fstream>
#include "stb_image.h"


//const GLfloat positions[] = {
//  0.0f, 0.5f, 0.0f,
//  -0.5f, -0.5f, 0.0f,
//  0.5f, -0.5f, 0.0f
//};
//
//const GLfloat colors[] = {
//  1.0f, 0.0f, 0.0f, 1.0f,
//  0.0f, 1.0f, 0.0f, 1.0f,
//  0.0f, 0.0f, 1.0f, 1.0f
//};
//
//const GLchar *vertexShaderSrc =
//  "attribute vec3 in_Position;" \
//  "attribute vec4 in_Color;" \
//  "" \
//  "varying vec4 ex_Color;" \
//  "" \
//  "void main()" \
//  "{" \
//  "  gl_Position = vec4(in_Position, 1.0);" \
//  "  ex_Color = in_Color;" \
//  "}" \
//  "";
//
//const GLchar *fragmentShaderSrc =
//  "varying vec4 ex_Color;" \
//  "void main()" \
//  "{" \
//  "  gl_FragColor = ex_Color;" \
//  "}" \
//  "";

Renderer::Renderer()
{
	// TODO: Move to Application::initialize
 // if(SDL_Init(SDL_INIT_VIDEO) < 0)
 // {
 //   throw std::exception();
 // }

	//window = SDL_CreateWindow("Lab 4 - Architecture",
 //   SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
 //   WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

 // if(!SDL_GL_CreateContext(window))
 // {
 //   throw std::exception();
 // }

 /* if(glewInit() != GLEW_OK)
  {
    throw std::exception();
  }*/

  //GLuint positionsVboId = 0;

  //// Create a new VBO on the GPU and bind it
  //glGenBuffers(1, &positionsVboId);

  //if(!positionsVboId)
  //{
  //  throw std::exception();
  //}

  //glBindBuffer(GL_ARRAY_BUFFER, positionsVboId);

  //// Upload a copy of the data from memory into the new VBO
  //glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

  //// Reset the state
  //glBindBuffer(GL_ARRAY_BUFFER, 0);

  //GLuint colorsVboId = 0;

  //// Create a colors VBO on the GPU and bind it
  //glGenBuffers(1, &colorsVboId);

  //if(!colorsVboId)
  //{
  //  throw std::exception();
  //}

  //glBindBuffer(GL_ARRAY_BUFFER, colorsVboId);

  //// Upload a copy of the data from memory into the new VBO
  //glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

  //// Reset the state
  //glBindBuffer(GL_ARRAY_BUFFER, 0);

  //vaoId = 0;

  //// Create a new VAO on the GPU and bind it
  //glGenVertexArrays(1, &vaoId);

  //if(!vaoId)
  //{
  //  throw std::exception();
  //}

  //glBindVertexArray(vaoId);

  //// Bind the position VBO, assign it to position 0 on the bound VAO and flag it to be used
  //glBindBuffer(GL_ARRAY_BUFFER, positionsVboId);
  //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void *)0);
  //glEnableVertexAttribArray(0);

  //// Bind the color VBO, assign it to position 1 on the bound VAO and flag it to be used
  //glBindBuffer(GL_ARRAY_BUFFER, colorsVboId);
  //glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void *)0);
  //glEnableVertexAttribArray(1);

  //// Reset the state
  //glBindBuffer(GL_ARRAY_BUFFER, 0);
  //glBindVertexArray(0);

  //GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
  //glShaderSource(vertexShaderId, 1, &vertexShaderSrc, NULL);
  //glCompileShader(vertexShaderId);
  //GLint success = 0;
  //glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);

  //if(!success)
  //{
  //  throw std::exception();
  //}

  //GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
  //glShaderSource(fragmentShaderId, 1, &fragmentShaderSrc, NULL);
  //glCompileShader(fragmentShaderId);
  //glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);

  //if(!success)
  //{
  //  throw std::exception();
  //}

  //programId = glCreateProgram();
  //glAttachShader(programId, vertexShaderId);
  //glAttachShader(programId, fragmentShaderId);
  //glBindAttribLocation(programId, 0, "in_Position");
  //glBindAttribLocation(programId, 1, "in_Color");

  //if(glGetError() != GL_NO_ERROR)
  //{
  //  throw std::exception();
  //}

  //glLinkProgram(programId);
  //glGetProgramiv(programId, GL_LINK_STATUS, &success);

  //if(!success)
  //{
  //  throw std::exception();
  //}

  //glDetachShader(programId, vertexShaderId);
  //glDeleteShader(vertexShaderId);
  //glDetachShader(programId, fragmentShaderId);
  //glDeleteShader(fragmentShaderId);

 /* bool quit = false;

  while(!quit)
  {
    SDL_Event event = {0};

    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_QUIT)
      {
        quit = true;
      }
    }

    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(programId);
    glBindVertexArray(vaoId);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glBindVertexArray(0);
    glUseProgram(0);

    SDL_GL_SwapWindow(window);*/
//  }

}


void Renderer::onDisplay()
{
	angle += 0.5f;

	glClearColor(0.10f, 0.15f, 0.25f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	shader->setUniform("u_Projection", glm::perspective(glm::radians(65.0f), 1.0f, 0.1f, 100.0f));

	shader->setUniform("u_Model", glm::rotate(glm::mat4(1.0f), glm::radians(10.0f), glm::vec3(1, 0, 0)) *
	glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0, 1, 0)) *
	glm::translate(glm::mat4(1.0f), glm::vec3(5, -2, 45)));

	shader->setMesh(mesh);
	shader->render();
}

void Renderer::RenderInitialise(char* _shader, char* _model, char* _texture)
{
	std::sr1::shared_ptr<Application> app = getApp();
	shader = app->context->createShader();
	{
		std::ifstream f(_shader);
		if (!f.is_open())
		{
			throw rend::Exception("cant open shader txt");
		}

		std::string shaderTxt;
		std::string pos;
		while (!f.eof())
		{
			std::getline(f, pos);
			shaderTxt += pos + "\n";
		}
		shader->parse(shaderTxt);
	}
	mesh = app->context->createMesh();
	{
		std::ifstream f(_model);
		if (!f.is_open())
		{
			throw rend::Exception("cant open model txt");
		}

		std::string modelTxt;
		std::string pos;
		while (!f.eof())
		{
			std::getline(f, pos);
			modelTxt += pos + "\n";
		}
		mesh->parse(modelTxt);
	}
	texture = app->context->createTexture();
	{
		int w = 0;
		int h = 0;
		int bpp = 0;

		unsigned char* data = stbi_load(_texture, &w, &h, &bpp, 3);
		if (!data)
		{
			throw rend::Exception("cant load texture");
		}
		texture->setSize(w, h);

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				int size = y * w * 3 + x * 3;

				texture->setPixel(x, y, glm::vec3(data[size] / 255.0f, data[size + 1] / 255.0f, data[size + 2] / 255.0f));

			}
		}
		stbi_image_free(data);
		mesh->setTexture("u_Texture", texture);
	}

}

Renderer::~Renderer()
{
	
}