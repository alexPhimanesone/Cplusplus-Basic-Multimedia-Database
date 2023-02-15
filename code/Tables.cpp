#include "Tables.h"


Photo_sp Tables::createPhoto(std::string _name, std::string _path, float _latitude, float _longitude)
{
    Photo_sp photo = Photo_sp(new Photo(_name, _path, _latitude, _longitude));
    multimedias.insert({_name, photo});
    return photo;
}

Video_sp Tables::createVideo(std::string _name, std::string _path, float _length)

{
    Video_sp video = Video_sp(new Video(_name, _path, _length));
    multimedias.insert({_name, video});
    return video;
}

Film_sp Tables::createFilm(std::string _name, std::string _path, float _length, int* _chapters, int _nbChapters)
{
    Film_sp film = Film_sp(new Film(_name, _path, _length, _chapters, _nbChapters));
    multimedias.insert({_name, film});
    return film;
}

Groupe_sp Tables::createGroupe(std::string _name)
{
    Groupe_sp groupe = Groupe_sp(new Groupe(_name));
    groupes.insert({_name, groupe});
    return groupe;
}

void Tables::search_multimedia(std::string name, std::stringstream* ss)
{
    std::map<std::string, Multimedia_sp>::const_iterator it = multimedias.find(name);
    if (it == multimedias.end())
        *ss << "Le multimedia \"" + name + "\" n'a pas été trouvé";
    else
        (it->second)->display(ss);
}

void Tables::search_groupe(std::string name, std::stringstream* ss)
{
    std::map<std::string, Groupe_sp>::const_iterator it = groupes.find(name);
    if (it == groupes.end())
        *ss << "Le groupe \"" + name + "\" n'a pas été trouvé";
    else
        (it->second)->display(ss);
}

void Tables::play(std::string name) const
{
    std::map<std::string, Multimedia_sp>::const_iterator it = multimedias.find(name);
    if (it == multimedias.end())
        std::cout << "Le multimedia \"" + name + "\" n'est pas présent" << std::endl;
    else
        (it->second)->play();
}

void Tables::delete_multimedia(std::string name)
{
    std::map<std::string, Multimedia_sp>::iterator multimedia_prime = multimedias.find(name);
    if (multimedia_prime == multimedias.end())
        std::cout << "Le multimedia \"" + name + "\" n'est pas présent" << std::endl;
    else
    {
        // Enlever le multimedia du dictionnaire multimedias
        multimedias.erase(name);
        // Enlever le multimedia de chacun des groupes auquel il appartenait
        for (std::map<std::string, Groupe_sp>::iterator groupe_prime = groupes.begin(); groupe_prime != groupes.end(); ++groupe_prime)
            (groupe_prime->second)->remove(multimedia_prime->second);
        // Detruire le multimedia
        (multimedia_prime->second).reset();
    }
}

void Tables::delete_groupe(std::string name)
{
    std::map<std::string, Groupe_sp>::iterator it = groupes.find(name);
    if (it == groupes.end())
        std::cout << "Le groupe \"" + name + "\" n'est pas présent" << std::endl;
    else
    {
        // Enlever le groupe du dictionnaire des groupes
        groupes.erase(name);
        // Detruire le groupe
        (it->second).reset();
    }
}