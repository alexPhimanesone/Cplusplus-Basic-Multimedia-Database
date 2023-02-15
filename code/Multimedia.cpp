#include "Multimedia.h"

Multimedia::Multimedia()
{
}

Multimedia::Multimedia(std::string _name, std::string _path)
{
    name = _name;
    path = _path;
}

Multimedia::~Multimedia()
{
}

std::string Multimedia::getName() const
{
    return name;
}

std::string Multimedia::getPath() const
{
    return path;
}

void Multimedia::setName(std::string _name)
{
    name = _name;
}

void Multimedia::setPath(std::string _path)
{
    path = _path;
}

void Multimedia::display(std::stringstream* ss)
{
    *ss << "Name: " + name;
    *ss << "Path: " + path;
}