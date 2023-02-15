//
// main.cpp
// Created on 21/10/2018
//

#define VERSION_Q11


#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "Multimedia.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "Groupe.h"
#include "Tables.h"
using namespace std;


const int PORT = 3331;


int main(int argc, const char* argv[])
{
    std::cout << "===============================" << std::endl;
    std::cout << "=============START=============" << std::endl;
    std::cout << "===============================" << std::endl;

    // Etape I.3
    // Multimedia* multimedia1 = new Multimedia("Avengers Endgame", "endgame.mp4");
    // multimedia1->display(std::cout);
    // multimedia1->setName("Endgame");
    // multimedia1->display(std::cout);

    //Etape I.4
    //std::string video_path = "./Data/Videos/earth.avi";
    //Video* video1 = new Video("earth video", video_path, 13.5);
    //video1->display(std::cout);
    //video1->play();
    //std::string photo_path = "./Data/Photos/laptop.png";
    //Photo* photo1 = new Photo("laptop photo", photo_path, 23.1, 27.7);
    //cout << photo1->getPath() << std::endl;
    //photo1->play();

    //Etape I.5
    //Multimedia** tab = new Multimedia*[4];
    //tab[0] = new Video("earth video", "./Data/Videos/earth.avi", 13.5);
    //tab[1] = new Photo("laptop photo", "./Data/Photos/laptop.png", 23.1, 27.7);
    //tab[2] = new Video("cats video", "./Data/Videos/cats.mp4", 14.6);
    //tab[3] = new Photo("balloons photo", "./Data/Photos/balloons.tif", 21.1, 33.0);
    //for(int i = 0; i < 4; i++)
    //{
    //    tab[i]->display(std::cout);
    //} 

    //Etape I.6
    //int* tab = new int[3]{7, 11, 4};
    //Film* film1 = new Film("earth video", "./Data/Videos/earth.avi", 13.5, tab, 3);
    //film1->display(std::cout);
    //tab[0] = 8;
    //film1->display(std::cout);
    //delete[] tab;
    //film1->display(std::cout);
    //int* chapters = film1->getChapters();
    //chapters[2] = 9;
    //film1->display(std::cout);

    //Etape I.7
    //int* tab1 = new int[3]{7, 11, 4};
    //Film* film1_ptr = new Film("earth video", "./Data/Videos/earth.avi", 13.5, tab1, 3);
    //Film film2(*film1_ptr);
    //int* tab3 = new int[4]{8, 1, 5, 4};
    //Film* film3_ptr = new Film("cat video", "./Data/Videos/cats.mp4", 100., tab3, 4);
    //*film3_ptr = *film1_ptr;
    //film3_ptr->display(std::cout);
    //film1_ptr->display(std::cout);
    //film3_ptr->setChapters(new int[5]{1, 333, 2, 4, 8}, 5);
    //film3_ptr->display(std::cout);
    //film1_ptr->display(std::cout);
    //*film3_ptr = film2;
    //film3_ptr->display(std::cout);

    //Etape I.8
    //int* tab1 = new int[3]{7, 11, 4};
    //int* tab2 = new int[4]{8, 1, 5, 4};
    //Film* film1 = new Film("earth video", "./Data/Videos/earth.avi", 13.5, tab1, 3);
    //Film* film2 = new Film("cat video", "./Data/Videos/cats.mp4", 100., tab2, 4);
    //Photo* photo1 = new Photo("laptop photo", "./Data/Photos/laptop.png", 23.1, 27.7);
    //Photo* photo2 = new Photo("cute photo", ".Data/Photos/cute.jpg", 10.0, 20.1);
    //Groupe* groupe1 = new Groupe();
    //groupe1->push_back(film1);
    //groupe1->push_back(photo1);
    //groupe1->push_back(film2);
    //groupe1->display(std::cout);
    //Groupe* groupe2 = new Groupe();
    //groupe2->push_back(photo1);
    //groupe2->push_back(photo2);
    //groupe2->display(std::cout);
    //delete groupe2;
    //groupe1->display(std::cout);

    //Etape I.9
    //int* tab1 = new int[3]{7, 11, 4};
    //int* tab2 = new int[4]{8, 1, 5, 4};
    //Film_sp film1 = Film_sp(new Film("earth video", "./Data/Videos/earth.avi", 13.5, tab1, 3));
    //Film_sp film2 = Film_sp(new Film("cat video", "./Data/Videos/cats.mp4", 100., tab2, 4));
    //Photo_sp photo1 = Photo_sp(new Photo("laptop photo", "./Data/Photos/laptop.png", 23.1, 27.7));
    //Photo_sp photo2 = Photo_sp(new Photo("cute photo", ".Data/Photos/cute.jpg", 10.0, 20.1));
    //Groupe* groupe1 = new Groupe();
    //groupe1->push_back(film1);
    //groupe1->push_back(photo1);
    //groupe1->push_back(film2);
    //Groupe* groupe2 = new Groupe();
    //groupe2->push_back(photo1);
    //groupe2->remove(photo1);
    //groupe1->display(std::cout);
    //groupe1->remove(film1);
    //groupe1->display(std::cout);
    /*
    REMARQUE:
    Un shared_pointer vers un multimedia qui n'est jamais
    ajouté à un groupe sera supprimé en fin de programme
    (car c'est une var locale sur la pile, donc supprimé
    quand on sort de main)
    */

#ifdef VERSION_Q10

    //Etape I.10
    Tables* tables = new Tables();
    int* tab1 = new int[3]{7, 11, 4};
    Photo_sp photo1 = tables->createPhoto("laptop photo", "./Data/Photos/laptop.png", 23.1, 27.7);
    Film_sp film1 = tables->createFilm("earth video", "./Data/Videos/earth.avi", 13.5, tab1, 3);
    tables->search_multimedia("cute photo");
    Groupe_sp groupe1 = tables->createGroupe("groupe1");
    Groupe_sp groupe2 = tables->createGroupe("groupe2");
    groupe1->push_back(photo1);
    groupe1->push_back(film1);
    groupe2->push_back(film1);
    tables->search_groupe("groupe1");
    tables->play("earth video");
    // Additionnel: méthode de suppression
    tables->delete_multimedia("earth video");
    std::cout << "New content of groupe1:" << std::endl;
    groupe1->display(std::cout);
    std::cout << "New content of groupe2:" << std::endl;
    groupe2->display(std::cout);

#endif


#ifdef VERSION_Q11

    //Etape I.11


    // Creation des tables
    Tables* tables = new Tables();
    int* tab1 = new int[3]{7, 11, 4};
    Photo_sp photo1 = tables->createPhoto("laptop_photo", "./Data/Photos/laptop.png", 23.1, 27.7);
    Film_sp film1 = tables->createFilm("earth_video", "./Data/Videos/earth.avi", 13.5, tab1, 3);
    Groupe_sp groupe1 = tables->createGroupe("groupe1");
    Groupe_sp groupe2 = tables->createGroupe("groupe2");
    groupe1->push_back(photo1);
    groupe1->push_back(film1);
    groupe2->push_back(film1);


    // Creation du TCPServer
    
    TCPServer* server =
    new TCPServer(
        [&](std::string const& request, std::string& response)
        {
            // Display the request sent by the client to the server
            std::cout << "request: " << request << std::endl;

            // Split the request into words
            stringstream request_stream;
            request_stream << request;
            array<string, 3> words;
            request_stream >> words[0];
            request_stream >> words[1];
            request_stream >> words[2];

            // Traitement de la requête

            stringstream response_stream;

            if (words[0] == "rechercher")
            {
                if (words[1] == "multimedia")
                    tables->search_multimedia(words[2], &response_stream);
                else if (words[1] == "groupe")
                    tables->search_groupe(words[2], &response_stream);
                else
                    response_stream << "Wrong request: " + request;
            }
            else if (words[0] == "jouer")
            {
                tables->search_multimedia(words[1], &response_stream);
                tables->play(words[1]);
            }
            else
                response_stream << "Wrong request: " + request;

            response = response_stream.str();
            
            // return false would close the connection with the client
            return true;
        }
    );

    // lance la boucle infinie du serveur
    std::cout << "Starting Server on port " << PORT << std::endl;
    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0)
    {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }


#endif


    return 0;
}
