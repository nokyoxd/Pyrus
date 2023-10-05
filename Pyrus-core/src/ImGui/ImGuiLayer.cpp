#include "ImGuiLayer.h"

#include "Core/Application.h"

#include <ImGui/imgui.h>
#include <ImGui/imgui_internal.h>
#include <ImGui/opengl3/imgui_impl_opengl3.h>
#include <ImGui/glfw/imgui_impl_glfw.h>

ImGuiLayer::ImGuiLayer()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    /* Disable file log */
    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = NULL;

    ImGui::StyleColorsDark();

    auto& app = Application::Get();
    GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow()->GetNativeWindow());

    const char* glsl_version = "#version 410";
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

ImGuiLayer::~ImGuiLayer()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void ImGuiLayer::Begin()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void ImGuiLayer::End()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

std::unique_ptr<ImGuiLayer> ImGuiLayer::Create()
{
	return std::make_unique<ImGuiLayer>();
}