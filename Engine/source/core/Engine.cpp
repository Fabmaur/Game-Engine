#include "pch.h"
#include "Engine.h"
#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw.h"
#include "vendor/imgui/imgui_impl_opengl3.h"

using namespace core;
using namespace graphics;

Engine::Engine(const int width, const int height)
{
	app = CreateApp();
	HP_STATUS("Initializing Engine");
	graphics::Window newWindow("Hello World!", width, height);
	window = newWindow;
	window.SetColour(0.2f, 0.4f, 0.3f, 1.0f);
}

Engine::Engine(const char* title, const int width, const int height)
{
	app = CreateApp();
	HP_STATUS("Initializing Engine");
	graphics::Window newWindow(title, width, height);
	window = newWindow;
	window.SetColour(0.4f, 0.2f, 0.6f, 1.0f);
}

void Engine::Start()
{
	app->Init();
	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(window.GetPointer(), true);
	ImGui::StyleColorsDark();

	ImGui_ImplOpenGL3_Init("#version 330");
	while (!window.IsWindowClosed())
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		app->RunMain();
		ImGui::ShowDemoWindow();
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		window.Update();
    }
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void core::Engine::Stop()
{
	window.Terminate();
}
