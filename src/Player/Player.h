#ifndef PROYECTO_JUEGO_PLAYER_H
#define PROYECTO_JUEGO_PLAYER_H

#include <iostream>
#include "../Map/Map.h"

enum DIRECTION {LEFT, RIGHT, UP, DOWN}; // Posiciones donde se 
class Player {
    public:
        Player();
        Player(int, int);
        void moveTo(DIRECTION, Map&);
        int getPosX() const;
        int getPosY() const;
        void setPos(int, int);
        void setPosX(int);
        void setPosY(int);

    private:
        int posX, posY;
        int lives = 3;

};


#endif //PROYECTO_JUEGO_PLAYER_H
