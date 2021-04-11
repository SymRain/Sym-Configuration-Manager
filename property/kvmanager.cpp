#include"./kvmanager.h"
#include<map>
#include"../file/filemanage.h"
#include"../file/normalfile.h"



unsigned int NormalKVmanager::OpenFile(std::string path)
{
    SymCommon::LinkNode<FileNode<FileManager*>>* filenode=new SymCommon::LinkNode<FileNode<FileManager*>>;
    filenode->data->data = new NormalFileManager;
    if(!filenode->data->data->Open(path))
    {
        delete filenode;
        return false;
    }
    SymCommon::LinkNode<FileNode<std::map<std::string,std::string>>>* mapnode= new SymCommon::LinkNode<FileNode<std::map<std::string,std::string>>>;
    SymCommon::AddBeforeRoot(this->fileroot,*filenode);
    SymCommon::AddBeforeRoot(this->maproot,*mapnode);
    mapnode->data->id=filecount;
    filenode->data->id=filecount++;
    this->ReadFile(*filenode->data->data,mapnode->data->data);
    return true;
}

bool NormalKVmanager::CloseFile(unsigned int id)
{
    SymCommon::LinkNode<FileNode<FileManager*>>* fileseek=this->fileroot.next;
    SymCommon::LinkNode<FileNode<std::map<std::string,std::string>>>* mapseek=this->maproot.next;
    while(fileseek!=&this->fileroot)
    {
        if(fileseek->data->id==id)
        {
            SymCommon::DelSrc(*fileseek);
            SymCommon::DelSrc(*mapseek);
            delete fileseek->data->data;
            delete fileseek;
            delete mapseek;
            return true;
        }
        fileseek=fileseek->next;
        mapseek=mapseek->next;
    }
    return false;
}

bool NormalKVmanager::GetValueInAll(std::string& key,std::string& value)
{
    SymCommon::LinkNode<FileNode<std::map<std::string,std::string>>>* mapseek=this->maproot.next;
    
    while(mapseek!=&this->maproot)
    {
        std::map<std::string,std::string>::iterator iter=mapseek->data->data.find(key);
        if(iter!=mapseek->data->data.end())
        {
            value=iter->second;
            return true;
        }
        mapseek=mapseek->next;
    }
    return false;
}

bool NormalKVmanager::GetValue(std::string& key,std::string& value, unsigned int id)
{
    SymCommon::LinkNode<FileNode<std::map<std::string,std::string>>>* mapseek=this->maproot.next;
    while(mapseek!=&this->maproot)
    {
        std::map<std::string,std::string>::iterator iter=mapseek->data->data.find(key);
        if(iter!=mapseek->data->data.end())
        {
            value=iter->second;
            return true;
        }
        mapseek=mapseek->next;
    }
    return false;
}

void NormalKVmanager::ReadFile(FileManager& file,std::map<std::string,std::string> map)
{
    std::string ret;
    while(file.ReadLine(ret)!=-1)
    {
        if(ret.find_first_of(this->skip)!=std::string::npos)
        {
            int pos=ret.find_first_of(this->equal);
            map[ret.substr(0,pos)]=ret.erase(0,pos);
        }
    }
}

const std::string& NormalKVmanager::GetConfigType()
{
    return this->type;
}

bool NormalKVmanager:: GetNowGroup (std::string& group)
{
    return false;
}

bool NormalKVmanager:: CdGroup(const std::string& group)
{
    return false;
}
bool NormalKVmanager:: GetValue(const std::string& key,std::string& value,const std::string group)
{
    return false;
}
bool NormalKVmanager:: Operate(std::string& commad)
{
    return false;
}

bool NormalKVmanager::CloseAllFile()
{
    SymCommon::LinkNode<FileNode<FileManager*>>* fileseek=this->fileroot.next->next;
    SymCommon::LinkNode<FileNode<std::map<std::string,std::string>>>* mapseek=this->maproot.next->next;
    while(fileseek->next!=&this->fileroot)
    {
        delete fileseek->prev;
        delete mapseek->prev;
        fileseek=fileseek->next;
        mapseek=mapseek->next;
    }
    delete fileseek;
    delete mapseek;
}

PropertyManager& NormalKVmanager::Create()
{
    return *(new NormalKVmanager);
}