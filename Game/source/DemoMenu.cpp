#include "DemoMenu.h"
#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw.h"
#include "vendor/imgui/imgui_impl_opengl3.h"
#include "events/Events.h"

void DemoMenu::onEvent(EventMessage & event)
{
	event.ifIs<WindowResize>([](WindowResize& resizeEvent)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2((float)resizeEvent.GetWidth(), (float)resizeEvent.GetHeight());
	});

	event.ifIs<MousePressed>([](MousePressed& pressedEvent)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[pressedEvent.GetButton()] = true;
	});

	event.ifIs<MouseReleased>([](MouseReleased& releasedEvent)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[releasedEvent.GetButton()] = false;
	});

	event.ifIs<MouseMoved>([](MouseMoved& movedEvent)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2((float)movedEvent.GetX(), (float)movedEvent.GetY());
	});

	event.ifIs<KeyPressed>([](KeyPressed& keyPressedEvent)
	{
		ImGuiIO& io = ImGui::GetIO();
		int keycode = keyPressedEvent.GetKeycode();
		if (keycode > 0 && keycode < 0x10000)
			io.AddInputCharacter((unsigned short)keycode);
	});
}

void DemoMenu::Init()
{
	SetActive(true);
	ImGui::CreateContext();
	ImGui::StyleColorsDark();
	ImGuiIO& io = ImGui::GetIO();
	io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
	io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

	// Keyboard mapping. ImGui will use those indices to peek into the io.KeysDown[] array.
	io.KeyMap[ImGuiKey_Tab] = KEY_TAB;
	io.KeyMap[ImGuiKey_LeftArrow] = KEY_LEFT;
	io.KeyMap[ImGuiKey_RightArrow] = KEY_RIGHT;
	io.KeyMap[ImGuiKey_UpArrow] = KEY_UP;
	io.KeyMap[ImGuiKey_DownArrow] = KEY_DOWN;
	io.KeyMap[ImGuiKey_PageUp] = KEY_PAGE_UP;
	io.KeyMap[ImGuiKey_PageDown] = KEY_PAGE_DOWN;
	io.KeyMap[ImGuiKey_Home] = KEY_HOME;
	io.KeyMap[ImGuiKey_End] = KEY_END;
	io.KeyMap[ImGuiKey_Insert] = KEY_INSERT;
	io.KeyMap[ImGuiKey_Delete] = KEY_DELETE;
	io.KeyMap[ImGuiKey_Backspace] = KEY_BACKSPACE;
	io.KeyMap[ImGuiKey_Space] = KEY_SPACE;
	io.KeyMap[ImGuiKey_Enter] = KEY_ENTER;
	io.KeyMap[ImGuiKey_Escape] = KEY_ESCAPE;
	io.KeyMap[ImGuiKey_A] = KEY_A;
	io.KeyMap[ImGuiKey_C] = KEY_C;
	io.KeyMap[ImGuiKey_V] = KEY_V;
	io.KeyMap[ImGuiKey_X] = KEY_X;
	io.KeyMap[ImGuiKey_Y] = KEY_Y;
	io.KeyMap[ImGuiKey_Z] = KEY_Z;

	ImGui_ImplOpenGL3_Init("#version 410");
	io.DisplaySize = ImVec2(1920, 1080);
}

void DemoMenu::RunMain()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui::NewFrame();
	ImGui::Text("Hello world!");

	for (auto& demo : demoes)
	{
		if (ImGui::Button(demo.first.c_str()))
		{
			demo.second->SetActive(true);
			currentDemo = demo.first;
			break;
		}
	}
	for (auto& demo : demoes)
	{
		if (demo.first != currentDemo)
			demo.second->SetActive(false);
	}



	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void DemoMenu::CreateDemo(const std::string& name, Layer* demo)
{
	demoes.insert(std::pair(name, demo));
}

DemoMenu::~DemoMenu()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}
