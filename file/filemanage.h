#ifndef FILE_MANAGER
#define FILE_MANAGER
#include"./common.h"
#include<string>
interface FileManager
{
public:
    virtual bool Open(std::string Path)=0;
    virtual bool Close()=0;
    virtual int ReadLine(std::string& ret)=0;
    virtual int ReadStopByChar(char StopChar,std::string& ret)=0;
    virtual bool IsOpen()=0;
    virtual int ReadBySize(std::string& ret, unsigned int size)=0;
    virtual std::string & GetPath()=0;
    //virtual bool IsReadEnd()=0;
};
#endif