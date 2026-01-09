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


namespace Visual::def
{
    inline constexpr const SDL_EventType  EXIT_EVENT     =    SDL_EVENT_QUIT;                  // Exit event
    inline constexpr const uint32_t       SDL_INIT_FLAGS =    SDL_INIT_VIDEO | SDL_INIT_AUDIO; // SDL initialization flags
    
    inline constexpr       float          VERSION        =    1.0f;                            // Engine version
    inline constexpr const char*          ENGINE_NAME    =    "Visual Engine";                 // Engine name
    inline constexpr       float          ON_EPSILON     =    0.1f;                            // Treshold value
}