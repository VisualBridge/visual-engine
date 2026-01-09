#pragma once
#include <imgui.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_opengl3.h>
#include "../core/visual_def.hxx"

namespace Visual::Editor
{
    inline void ApplyElectronStyle()
    {
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable snapping windows
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Let windows leave the main frame

        ImGui::StyleColorsDark();
        auto& style                     = ImGui::GetStyle();
        style.WindowRounding            = 0.0f;
        style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1f, 0.12f, 1.0f);
    }

    inline void Init(SDL_Window* window, SDL_GLContext context)
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ApplyElectronStyle();

        ImGui_ImplSDL3_InitForOpenGL(window, context);
        ImGui_ImplOpenGL3_Init("#version 440");
    }
}