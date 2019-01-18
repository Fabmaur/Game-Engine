cmake_minimum_required(VERSION 3.7)

project(GameEngine)

message(STATUS ${PROJECTNAME})
set_target_properties(${PROJECTNAME} PROPERTIES LINKER_LANGUAGE CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (Game_Engine_VERSION_MAJOR 1)
set (Game_Engine_VERSION_MINOR 0)
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


set(glfw3_DIR ${CMAKE_SOURCE_DIR}/Dependencies/GLFW/lib/cmake/glfw3)
find_package(glfw3 REQUIRED)

set(glew_DIR ${CMAKE_SOURCE_DIR}/Dependencies/GLEW)
find_library(glew glew32s "${glew_DIR}/lib/Release/Win32")

include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${glew_DIR}/include)

target_link_libraries(
        engine
        glfw
        glew
)

set(GAME_DIR ${CMAKE_SOURCE_DIR}/Game/source)
set(GAME_SOURCES ${GAME_DIR}/main.cpp)

add_executable(engine_game ${GAME_SOURCES})

target_link_libraries(engine_game engine)