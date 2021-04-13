#include<string>
#include"./sympropertymanage.h"


struct ManagerNode
{
    PropertyManager*(*Create)();
    std::string type;
};

class ConfigManager
{
private:
    static const int managercount;
    static ManagerNode pronode[1];
public:
    static PropertyManager* GetNewManager(std::string & type);
};



