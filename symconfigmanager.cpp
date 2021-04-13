#include"./symconfigmanager.h"
#include"./property/property.h"
PropertyManager* ConfigManager::GetNewManager(std::string & type)
{
    for(int index=0;index<ConfigManager::managercount;++index)
    {
        if(pronode[index].type.compare(type)==0)
        {
            return pronode[index].Create();
        }
    }
}

ManagerNode ConfigManager::pronode[] ={
        {NormalKVmanager::Create,"NormalKV"},
    };

const int ConfigManager::managercount=1;