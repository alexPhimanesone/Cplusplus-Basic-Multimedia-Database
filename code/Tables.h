#ifndef __TABLES_H__
#define __TABLES_H__

#include "Multimedia.h"
#include "Photo.h"
#include "Groupe.h"
#include "Video.h"
#include "Film.h"
#include <map>

class Tables
{
    protected:
        std::map<std::string, Multimedia_sp> multimedias{};
        std::map<std::string, Groupe_sp> groupes{};
    public:
        Photo_sp createPhoto(std::string _name, std::string _path, float _latitude, float _longitude);
        Video_sp createVideo(std::string _name, std::string _path, float _length);
        Film_sp createFilm(std::string _name, std::string _path, float _length, int* _chapters, int _nbChapters);
        Groupe_sp createGroupe(std::string _name);
        void search_multimedia(std::string name, std::stringstream* ss);
        void search_groupe(std::string name, std::stringstream* ss);
        void play(std::string name) const;
        void delete_multimedia(std::string name);
        void delete_groupe(std::string name);
};

#endif