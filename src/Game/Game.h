// Un proyecto elaborado por: 
// Andrés Alejandro Guzmán González - A01633819
// José Pablo Naime García - A01367610
// © 2021 José Pablo Naime García Andrés Alejandro Guzmán González All Rights Reserved

#ifndef PROYECTO_JUEGO_GAME_H
#define PROYECTO_JUEGO_GAME_H

#include "./../Map/Map.h"
#include "./../Room/Room.h"
#include "./../Item/Item.h"
#include "./../Player/Player.h"
#include <boost/algorithm/string.hpp>

enum GAME_STATE {START, IN_GAME, END};


class Game {
    public:
        Game(Map* map, Player* player);

        void setGameState(GAME_STATE);
        GAME_STATE getGameState() const;
        
        void start();
        void gameLoop();
        void getInput();
        void logic();
        void display();
        static void clearScreen(float);
        static void addDelay(float); // Agrega delay en la consola
        static void printTextFile(string, float, bool, bool);
        static void enterToContinue();
    private:
        bool canInput = false;
        GAME_STATE gameState;
        PLAYER_CONTEXT playerContext;
        Player* player;
        Map* map;
};


#endif //PROYECTO_JUEGO_GAME_H
