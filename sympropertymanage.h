#include<string>
#define interface class
interface PropertyManager
{
public:
    virtual unsigned int OpenFile(std::string path)=0;
    virtual bool CloseFile(unsigned int id)=0;
    virtual const std::string& GetConfigType()=0;
    virtual bool GetValue(std::string& key,std::string& value, unsigned int id=0)=0;
    virtual bool GetValueInAll(std::string& key,std::string& value)=0;
    virtual bool IsGrouped()=0;
    virtual bool GetNowGroup(std::string& group)=0;
    virtual bool CdGroup(const std::string& group)=0;
    virtual bool GetValue(const std::string& key,std::string& value,const std::string group)=0;
    virtual bool Operate(std::string& commad)=0;
    //static bool Create()=0; 
};