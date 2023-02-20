#include "Film.h"


//méthode de copie profonde
int* Film::copy(int* tab, int size) const
{
    if (size == 0) return nullptr;
    
    int* new_tab = new int[size];
    for (int i = 0; i < size; i++)
    {
        new_tab[i] = tab[i];
    }
    return new_tab;
}

Film::Film(std::string _name, std::string _path, float _length, int* _chapters, int _nbChapters)
    : Video(_name, _path, _length)
{
    chapters = copy(_chapters, _nbChapters);
    nbChapters = _nbChapters;
}

Film::~Film()
{
    delete[] chapters;
}

Film::Film(const Film& from)
    : Video(from)
{
    chapters = from.chapters? copy(from.chapters, from.nbChapters) : nullptr;
    nbChapters = from.nbChapters;
}        

//redéfinition de = pour faire de la copie profonde
Film& Film::operator=(const Film& from)
{
    Video::operator=(from);
    if (chapters && from.chapters)
        chapters = copy(from.chapters, from.nbChapters);
    else
    {
        delete[] chapters;
        chapters = from.chapters ? copy(from.chapters, from.nbChapters) : nullptr;
    }
    nbChapters = from.nbChapters;
    return *this;
}

int* Film::getChapters() const
{
    return copy(chapters, nbChapters);
}

void Film::setChapters(int* _chapters, int _nbChapters)
{
    if (_nbChapters == 0)
    {
        chapters = nullptr;
        nbChapters = 0;
    }
    else
    {
        //les pointés sont stockés sur le tas
        delete[] chapters;
        chapters = copy(_chapters, _nbChapters);
        nbChapters = _nbChapters;
    }
}

void Film::display(std::stringstream* ss)
{
    *ss << "Name: " + name + ", ";
    *ss << "Path: " + path + ", ";
    *ss << "Length: " << length << ", ";
    for (int i = 0; i < nbChapters; i++)
    {
        *ss << "Duree du chapitre " << i+1 << ": " << *(chapters + i);
        if (i != nbChapters - 2) {*ss << ", ";}
    } 
}