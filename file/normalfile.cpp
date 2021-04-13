#include"./normalfile.h"


NormalFileManager::NormalFileManager(std::string& Path)
{
    Open(Path);
}

NormalFileManager::NormalFileManager()
{}
bool NormalFileManager::Open(std::string Path)
{
    this->path=Path;
    file.open(path);
    return file.is_open();
}

bool NormalFileManager::Close()
{
    this->file.close();
    return true;
}

int NormalFileManager::ReadLine(std::string& ret)
{
    
    std::getline(this->file, ret);
    if(!this->file.eof())
        return ret.length();
    else
        return -1;
}

int NormalFileManager::ReadStopByChar(char StopChar,std::string& ret)
{
    std::getline(this->file,ret,StopChar);
    return ret.length();
}

NormalFileManager::~NormalFileManager()
{
    this->Close();
}

bool NormalFileManager::IsOpen()
{
    return this->file.is_open();
}

int NormalFileManager::ReadBySize(std::string& ret, unsigned int size)
{
    char* buff= new char[size];
    this->file.read(buff,size);
    ret=buff;
    return ret.length();
}
