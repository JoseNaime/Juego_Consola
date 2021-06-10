#ifndef PROYECTO_JUEGO_GAME_H
#define PROYECTO_JUEGO_GAME_H

#include "./../Map/Map.h"
#include "./../Room/Room.h"
#include "./../Item/Item.h"
#include "./../Player/Player.h"


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
        static void addDelay(float);
        static void printTextFile(string, float);
        static void printTextFile(string, float, bool);
        static void setGlobalInput();
    private:
        GAME_STATE gameState;
        Player* player;
        Map* map;
};


#endif //PROYECTO_JUEGO_GAME_H
