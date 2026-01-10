#include "cvar.hxx"

using namespace Visual::Core;

Visual::Core::CVarManager::~CVarManager() 
{ 
    // RAM is expensive
    for (auto const &[name, var] : m_vars) 
    {
        delete var;
    }

  m_vars.clear();
}

void CVarManager::Register(std::string &name, const std::string &defValue,
                           bool archive) {
  if (m_vars.find(name) != m_vars.end())
    return;
  CVar *newVar = new CVar();
  newVar->name     =   _strdup(name.c_str());
  newVar->string   =   _strdup(defValue.c_str());
  newVar->value    =   std::stof(defValue);
  newVar->archive  =   archive;
  m_vars[name]     =   newVar;
}

void CVarManager::Set(const std::string& name , const std::string& value)
{
  auto it = m_vars.find(name);
  if (it != m_vars.end()) 
  {
        if (it->second->string) 
        {
            free(it->second->string);
        }
	    it->second->string =   _strdup(value.c_str());   
	    it->second->value  =   std::stof(value);
  }
}

char *CVarManager::Find(const std::string &name) 
{
  auto it = m_vars.find(name);
  if (it != m_vars.end()) {
    return it->second->string;
  }
  return nullptr;
}
