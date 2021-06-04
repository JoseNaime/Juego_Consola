#ifndef PROYECTO_JUEGO_PLAYER_H
#define PROYECTO_JUEGO_PLAYER_H

#include <iostream>
#include <vector>

#include "../Character/Character.h"
#include "../Map/Map.h"

using namespace std;

enum DIRECTION {LEFT, RIGHT, UP, DOWN}; // Posiciones donde se 
class Player : public Character {
    public:
        Player();
        Player(string, int, int, int, int); // name, lives, damage, x, y
        void moveTo(DIRECTION, Map&);
        void useItem(&Item);

        int getPosX() const;
        int getPosY() const;
        void setPos(int, int);
        void setPosX(int);
        void setPosY(int);

    private:
        int posX, posY;
        Item[4] inventory
        

};


#endif //PROYECTO_JUEGO_PLAYER_H
