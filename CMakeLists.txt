cmake_minimum_required(VERSION 2.6)
project(MYENGINE)

include_directories(src)

add_library(rend
  src/rend/Exception.cpp
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
  src/rend/Mesh.cpp
  src/rend/Util.cpp
)
if (MSVC)
target_link_libraries(rend glew32 opengl32)
else()
target_link_libraries(rend GLEW GL)
endif()


add_library(engine
src/engine/Application.h
src/engine/Application.cpp
src/engine/Entity.h
src/engine/Entity.cpp
src/engine/Component.h
src/engine/Component.cpp
src/engine/Renderer.h
src/engine/Renderer.cpp
src/engine/Exception.h
src/engine/Exception.cpp
src/engine/stb_image.h
)
target_link_libraries(engine SDL2 opengl32 glew32)

add_executable(game
	src/game/main.cpp
)
target_link_libraries(game engine)