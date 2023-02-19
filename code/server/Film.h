#ifndef __FILM_H__
#define __FILM_H__

#include<memory>
#include "Video.h"

class Film : public Video
{
    friend class Tables;
    
    protected:
        int* chapters{};
        int nbChapters{};
        Film() {};
        Film(std::string _name, std::string _path, float _length, int* _chapters, int _nbChapters);
        Film(const Film& from);
        Film& operator=(const Film& from);
    public:
        ~Film();
        int* copy(int* tab, int size) const;
        int* getChapters() const;
        int getNbChapters() const {return nbChapters;}
        void setChapters(int* _chapters, int _nbChapters);
        void display(std::stringstream* ss);
};

typedef std::shared_ptr<Film> Film_sp;

#endif
