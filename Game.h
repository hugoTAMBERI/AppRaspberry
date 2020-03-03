//
// Created by hugo on 03/03/2020.
//
#include <thread>
#include <mutex>
#include "Color.h"

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H


class Game {
private :
    int REQUEST_IMAGE_CAPTURE = 1;
    //UdpServeur mudpServeur;
    int derniereColonneTube;
    int derniereColonneDessine;
    int positionJoueur;
    int mp_CentrePassage;
    int decalageJoueurConrrant;
    int * decalage;
    unsigned char * byteMap;
    std::mutex semaphore;
    bool isStart;
    bool perdu;

    Color BG_COLOR = Color(51, 204, 255);
    Color PIPE_COLOR  = Color(8, 155, 0);
    Color B_PLAYER_COLOR = Color(240, 243, 33);
    Color E_PLAYER_COLOR =  Color(0, 0, 0);
    Color W_PLAYER_COLOR =  Color(243, 7, 31);
    Color WHITE_COLOR =  Color(250, 250, 250);


public:
    void init_game() ;
    void update();
    void MoveJoueur();
    void addPipe(int debut, int fin);
    void decaler();
    void updateGame();
};


#endif //UNTITLED_GAME_H
