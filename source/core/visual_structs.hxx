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
#include <memory>

namespace Visual::structs
{
    struct Entity 
    {
        uint32_t                                id;                  // unique id for entity
        std::string                             name;                // name of entity
        std::vector<std::unique_ptr<Component>> components;          // list of components

        template<typename T, typename... Args>
        T& AddComponent(Args&&... args) 
        {
            components.push_back(std::make_unique<T>(std::forward<Args>(args)...));
            return *static_cast<T*>(components.back().get());
        }
    };
    struct Scene
    {
        using EntityList = std::vector<Entity>;
        using EntityMap  = std::unordered_map<std::string, Entity>;
    };
    class Component 
    {
      public:
        virtual ~Component() = default;
        virtual void OnUpdate(float delta) {}
        virtual void OnRender() {}
    };
}