#ifndef __MULTIMEDIA_H__
#define __MULTIMEDIA_H__

#include <string>
#include <iostream>
#include <sstream>
#include<memory>

class Multimedia
{
    friend class Tables;
    
    protected:
        std::string name{};
        std::string path{};
    public:
        Multimedia();
        Multimedia(std::string _name, std::string _path);
        virtual ~Multimedia();
        std::string getName() const;
        std::string getPath() const;
        void setName(std::string _name);
        void setPath(std::string _path);
        virtual void display(std::stringstream* ss);
        virtual void play() const =0;
};

typedef std::shared_ptr<Multimedia> Multimedia_sp;

#endif