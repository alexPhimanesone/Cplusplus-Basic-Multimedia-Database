#ifndef __VIDEO_H__
#define __VIDEO_H__

#include<memory>
#include "Multimedia.h"

class Video : public Multimedia
{
    friend class Tables;
    
    protected:
        float length{};
        Video() {};
        Video(std::string _name, std::string _path, float _length)
            : Multimedia(_name, _path)
        {
            length = _length;
        }
    public:
        ~Video() {std::cout << "The video: \"" + name + "\" is going to die" << std::endl;};
        float getLength() const {return length;}
        void setLength(float _length) {length = _length;}
        void display(std::stringstream* ss) override
        {
            *ss << "Name: " + name + ", ";
            *ss << "Path: " + path + ", ";
            *ss << "Length: " << length;
        }
        void play() const {system(std::string("mpv --no-terminal " + path + " &").data());}
};

typedef std::shared_ptr<Video> Video_sp;

#endif
