cmake_minimum_required(VERSION 3.7)

project(Hyperion_Engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/Engine/source)

set(ENGINE_SOURCES ${SOURCE_DIR}/core/Engine.cpp
		   ${SOURCE_DIR}/graphics/gl_types/IndexBuffer.cpp
 		   ${SOURCE_DIR}/graphics/gl_types/VertexArray.cpp
		   ${SOURCE_DIR}/graphics/gl_types/VertexBuffer.cpp
   		   ${SOURCE_DIR}/graphics/renderer/Camera.cpp
		   ${SOURCE_DIR}/graphics/renderer/Shader.cpp
		   ${SOURCE_DIR}/graphics/renderer/Texture.cpp
		   ${SOURCE_DIR}/graphics/renderer/Window.cpp
		   ${SOURCE_DIR}/vendor/stb_image/stb_image.cpp)

add_library(engine STATIC ${ENGINE_SOURCES})
target_include_directories(engine PUBLIC ${SOURCE_DIR})


#set(glfw3_DIR ${CMAKE_SOURCE_DIR}/Dependencies/GLFW/lib/cmake/glfw3)
#find_package(glfw3 3.2 REQUIRED)

set(GLFW_DIR ${CMAKE_SOURCE_DIR}/Dependencies/GLFW)
set(GLFW_SOURCE ${GLFW_DIR}/lib-vc2015)
find_library(glfw glfw3 ${GLFW_SOURCE})
find_package(OpenGL REQUIRED)

set(glew_DIR ${CMAKE_SOURCE_DIR}/Dependencies/GLEW)
find_library(glew glew32s "${glew_DIR}/lib/Release/Win32")
add_compile_definitions(GLEW_STATIC)


include_directories(${GLFW_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/Dependencies/GLFW/include)
include_directories(${glew_DIR}/include)
include_directories(${OPENGL_INCLUDE_DIR})

target_link_libraries(
        engine
		${glfw}
		${glew}
		${OPENGL_gl_LIBRARY}
)

set(GAME_DIR ${CMAKE_SOURCE_DIR}/Game/source)
set(GAME_SOURCES ${GAME_DIR}/main.cpp)

add_executable(hyperion_game ${GAME_SOURCES})

target_link_libraries(hyperion_game engine)