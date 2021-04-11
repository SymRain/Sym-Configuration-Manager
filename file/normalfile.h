#ifndef NORMAILFILE
#define NORMAILFILE
#include"./filemanage.h"
#include<fstream>
#include<string>
class NormalFileManager:public FileManager
{
private:
    std::fstream file;
    std::string path;
public:
    NormalFileManager(std::string& Path);
    NormalFileManager();
    virtual bool Open(std::string Path);
    virtual bool Close();
    virtual int ReadLine(std::string& ret);
    virtual int ReadStopByChar(char StopChar,std::string& ret);
    virtual std::string & GetPath();
    virtual bool IsOpen();
    virtual int ReadBySize(std::string& ret, unsigned int size);
    virtual ~NormalFileManager();
public:

}; 
#endif