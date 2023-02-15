#ifndef __GROUPE_H__
#define __GROUPE_H__

#include "Multimedia.h"
#include <list>

class Groupe : public std::list<Multimedia_sp>
{
    friend class Tables;

    protected:
        std::string name{};
        Groupe() {};
        Groupe(std::string _name)
            : Groupe()
        {
            name = _name;
        }
    public:
        std::string getName() const {return name;}
        void display(std::stringstream* ss)
        {
            for (std::list<Multimedia_sp>::const_iterator it = begin(); it != end(); ++it)
                (*it)->display(ss);
        }
};

typedef std::shared_ptr<Groupe> Groupe_sp;

#endif