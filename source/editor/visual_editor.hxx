/*
===============================================================================

    VISUAL ENGINE
    Developed by VISUAL BRIDGE

    Copyright (C) 2026 Visual Bridge. All Rights Reserved.
    Based on Quake (TM) Technology
    Copyright (C) 1996-1997 Id Software, Inc.

===============================================================================

    This project is open-source under the GPL-2 License.
    See LICENSE for the full text.

===============================================================================
*/
#pragma once
#include "../core/visual_def.hxx"
#include <imgui_impl_sdl3.h>
#include <imgui.h>
//#include IMGUI_SDL // Intellisense issues
#include <imgui_impl_opengl3.h>
#include <SDL3/SDL.h>

namespace Visual::Editor
{
    inline void ApplyMonolithStyle() // Thanks Gemini for this name
    {
        auto& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable snapping windows
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Let windows leave the main frame

        ImGui::StyleColorsDark();
        auto& style = ImGui::GetStyle();
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1f, 0.12f, 1.0f);
    }

    inline void Init(SDL_Window* window, SDL_GLContext context)
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ApplyMonolithStyle();

        ImGui_ImplSDL3_InitForOpenGL(window, context);
        ImGui_ImplOpenGL3_Init("#version 440");
    }
}