#ifndef PROYECTO_JUEGO_ROOM_H
#define PROYECTO_JUEGO_ROOM_H

#include "./../Item/Item.h"
#include "string"
using namespace std;

class Room {
    public:
        Room();
        Room(string, string, Item* items[3], int, int, bool);

        string getName() const;
        string getInitDescription() const;
        int getPosX() const;
        int getPosY() const;

        void setName(string);
        void setInitDescription(string);
        void setPosition(int[2]);
        void setPosition(int, int);
        void printInfo();
    private:
        string name, initDescription;
        Item* items[3];
        int posX, posY;
        bool locked;

};

#endif //PROYECTO_JUEGO_ROOM_H