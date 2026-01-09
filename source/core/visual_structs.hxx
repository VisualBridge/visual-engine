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
#include <glm/glm.hpp>
#include <vector>
#include <unordered_map>
#include <string>

namespace Visual::structs
{
    struct Entity 
    {
        uint32_t    id;
        std::string name;
        glm::vec3   position = { 0,0,0 };
        glm::vec3   rotation = { 0,0,0 };
        int         modelIndex = 0;
    };
    struct Scene
    {
        using EntityList = std::vector<Entity>;
        using EntityMap  = std::unordered_map<std::string, Entity>;
    };
}