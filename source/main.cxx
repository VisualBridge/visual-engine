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


#include <iostream>
#include <string>

#define  SDL_MAIN_HANDLED
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "core/visual_def.hxx"
#include "core/common.hxx"

#include <hl.h>

#include "core/cvar.hxx"

int main() 
{
    static cvar_t engine_version = {"visual_version", "0.0.1", qtrue};
    hl_global_init();

    SDL_SetMainReady();

    if (!SDL_Init(Visual::def::SDL_INIT_FLAGS)) {
        std::cout << "Engine failed to start: " << SDL_GetError() << std::endl;
        return -1;
    }
    SDL_Window* window = SDL_CreateWindow(Visual::def::ENGINE_NAME, 1280, 720, SDL_WINDOW_OPENGL);
    while (Visual::Common::IsRunning)
    {
        Visual::Common::PollEvents();

    }

    SDL_DestroyWindow(window);
    SDL_Quit();
	return 0;
}