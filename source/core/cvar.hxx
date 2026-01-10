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
#include <iostream>
#include <fstream>
#include <filesystem>
#include <unordered_map>
#include <cstring>

/* extern "C" 
{
	#include "cvar.h"
}
*/


namespace Visual::Core 
{
    struct CVar {
        char   *  name    ;
        char   *  string  ;
        float     value   ;
        bool      archive ;  // if true, save to a .cfg file
        ~CVar() {
          free(name);
          free(string);
        }
    };

    class CVarManager {
    public:
        virtual ~CVarManager();
        
        void Register(std::string& name, const std::string& defValue, bool archive = false);   // register a cvar

        void Set(const std::string& name, const std::string& value);                           // set a cvar's value
        
        char* Find(const std::string& name);                                                   // find a cvar's value
    
    private:
      std::unordered_map<std::string, CVar *> m_vars;                                       // map of cvars
    };
} // namespace Visual::Core