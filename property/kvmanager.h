#ifndef KV_MANAGER
#define KV_MANAGER
#include"../sympropertymanage.h"
#include"../common.h"
#include"../file/normalfile.h"
#include<map>

template<class T>
struct FileNode
{
    unsigned int id;
    T data;
};

class NormalKVmanager:public PropertyManager
{
private:
    unsigned int filecount=0;
    SymCommon::LinkNode<FileNode<FileManager*>> fileroot;
    SymCommon::LinkNode<FileNode<std::map<std::string,std::string>>> maproot;
    const std::string type="NormalKV";
    const char skip='#';
    const char equal='=';
public:
    virtual unsigned int OpenFile(std::string path);
    virtual bool CloseFile(unsigned int id);
    virtual bool GetValueInAll(std::string& key,std::string& value);
    virtual bool GetValue(std::string& key,std::string& value, unsigned int id=0);
    virtual bool IsGrouped(){return false;}
    virtual const std::string& GetConfigType();
    virtual bool GetNowGroup(std::string& group);
    virtual bool CdGroup(const std::string& group);
    virtual bool GetValue(const std::string& key,std::string& value,const std::string group);
    virtual bool Operate(std::string& commad);
    virtual bool CloseAllFile();
private:
    void ReadFile(FileManager& file,std::map<std::string,std::string> map);
public:
    static PropertyManager* Create();
    
};
#endif