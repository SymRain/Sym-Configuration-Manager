#include<string>
#include"./sympropertymanage.h"
#include"./property/property.h"

struct ManagerNode
{
    PropertyManager&(*Create)();
    std::string type;
};

class ConfigManager
{
private:
    static const int managercount;
    static ManagerNode pronode[1];
public:
    PropertyManager& GetNewManager(std::string & type);
};

ManagerNode ConfigManager::pronode[] ={
        {NormalKVmanager::Create,"NormalKV"},
    };

const int ConfigManager::managercount=1;

PropertyManager& ConfigManager::GetNewManager(std::string & type)
{
    for(int index=0;index<ConfigManager::managercount;++index)
    {
        if(pronode[index].type.compare(type)==0)
        {
            return pronode[index].Create();
        }
    }
}
