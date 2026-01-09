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
#include <SDL3/SDL.h>
#include "visual_def.hxx"

namespace Visual::Common 
{
    inline bool IsRunning = true;

    inline void PollEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == Visual::def::EXIT_EVENT) {
                IsRunning = false;
            }

        }
    }
}