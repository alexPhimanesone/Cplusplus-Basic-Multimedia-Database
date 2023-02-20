#ifndef __PHOTO_H__
#define __PHOTO_H__

#include<memory>
#include "Multimedia.h"

class Photo : public Multimedia
{
    friend class Tables;
    
    protected:
        float latitude{};
        float longitude{};
        Photo() {};
        Photo(std::string _name, std::string _path, float _latitude, float _longitude)
            : Multimedia(_name, _path)
        {
            latitude = _latitude;
            longitude = _longitude;
        }
    public:
        ~Photo() {std::cout << "The photo: \"" + name + "\" is going to die" << std::endl;};
        float getLatitude() const {return latitude;}
        float getLongitude() const {return longitude;;}
        void setLatitude(float _latitude) {latitude = _latitude;}
        void setLongitude(float _longitude) {longitude = _longitude;}
        void display(std::stringstream* ss) override
        {
            *ss << "Name: " + name + ", ";
            *ss << "Path: " + path + ", ";
            *ss << "Latitude: " << latitude << ", ";
            *ss << "Longitude: " << longitude;
        }
        void play() const {system(std::string("imagej " + path + " &").data());}
};

typedef std::shared_ptr<Photo> Photo_sp;

#endif
