#ifndef PROYECTO_JUEGO_ROOM_H
#define PROYECTO_JUEGO_ROOM_H

#include "string"
#include "./../Item/Item.h"

using namespace std;
class Room {
    public:
        Room();
        Room(string, string, Item* items[3], int, int);

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

};

#endif //PROYECTO_JUEGO_ROOM_H