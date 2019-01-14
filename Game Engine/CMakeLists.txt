cmake_minimum_required(VERSION 3.7)

project(Game_Engine)

set(CMAKE_CXX_STANDARD 14)

set (Game_Engine_VERSION_MAJOR 1)
set (Game_Engine_VERSION_MINOR 0)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/source)

set(ENGINE_SOURCES ${SOURCE_DIR}/core/Engine.cpp
		   ${SOURCE_DIR}/core/Engine.h
		   ${SOURCE_DIR}/debug/GLDebug.h
		   ${SOURCE_DIR}/graphics/gl_types/Buffers.h
 		   ${SOURCE_DIR}/graphics/gl_types/IndexBuffer.cpp
 		   ${SOURCE_DIR}/graphics/gl_types/IndexBuffer.h
 		   ${SOURCE_DIR}/graphics/gl_types/VertexArray.cpp
 		   ${SOURCE_DIR}/graphics/gl_types/VertexArray.h
 		   ${SOURCE_DIR}/graphics/gl_types/VertexBuffer.cpp
 		   ${SOURCE_DIR}/graphics/gl_types/VertexBuffer.h
 		   ${SOURCE_DIR}/graphics/renderer/simple_shapes/Cube.h
 		   ${SOURCE_DIR}/graphics/renderer/simple_shapes/Shapes.h
 		   ${SOURCE_DIR}/graphics/renderer/simple_shapes/Square.h
 		   ${SOURCE_DIR}/graphics/renderer/simple_shapes/Triangle.h
 		   ${SOURCE_DIR}/graphics/renderer/Camera.cpp
 		   ${SOURCE_DIR}/graphics/renderer/Camera.h
 		   ${SOURCE_DIR}/graphics/renderer/Shader.cpp
 		   ${SOURCE_DIR}/graphics/renderer/Shader.h
 		   ${SOURCE_DIR}/graphics/renderer/Texture.cpp
 		   ${SOURCE_DIR}/graphics/renderer/Texture.h
 		   ${SOURCE_DIR}/graphics/renderer/Window.cpp
 		   ${SOURCE_DIR}/graphics/renderer/Window.h
		   ${SOURCE_DIR}/maths/maths.h
		   ${SOURCE_DIR}/maths/MathsFunc.h
		   ${SOURCE_DIR}/maths/Matrix.h
		   ${SOURCE_DIR}/maths/Matrix2.h
		   ${SOURCE_DIR}/maths/Matrix3.h
		   ${SOURCE_DIR}/maths/Matrix4.h
		   ${SOURCE_DIR}/maths/Vector.h
 		   ${SOURCE_DIR}/graphics/renderer/Camera.cpp
 		   ${SOURCE_DIR}/vendor/stb_image/stb_image.cpp
 		   ${SOURCE_DIR}/graphics/renderer/stb_image.h
)

add_library(game_engine ${ENGINE_SOURCES})

set(GLFW_SOURCE ${CMAKE_SOURCE_DIR}/../Dependencies/GLFW/include/GLFW/glfw3.h)
add_library(glfw ${GLFW_SOURCE})

set(GLEW_SOURCE ${CMAKE_SOURCE_DIR}/../Dependencies/GLEW/include/GL/glew.h)
add_library(glew ${GLEW_SOURCE})

target_link_libraries(
        game_engine
        glfw
        glew
)


set(GAME_DIR ${CMAKE_SOURCE_DIR}/game)

target_link_libraries(game game_engine)

add_executable(game ${GAME_DIR}/source/main.cpp)