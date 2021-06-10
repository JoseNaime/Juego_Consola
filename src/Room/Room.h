#ifndef PROYECTO_JUEGO_ROOM_H
#define PROYECTO_JUEGO_ROOM_H

#include "./../Item/Item.h"
#include <iostream>
#include "string"
using namespace std;

class Room {
    public:
        Room();
        Room(string, string, Item* items[], int, int, bool);
    
        int getPosX() const;
        int getPosY() const;
        
        string getName() const;
        void setName(string);
        string getInitDescriptionUrl() const;
        void setInitDescriptionUrl(string);
        int* getPosition() const;
        void setPosition(int[2]);
        void setPosition(int, int);
        void setLocked(bool);
        bool getLocked();
        void printInfo();
    private:
        string name, initDescriptionUrl;
        Item* items[3];
        int posX, posY;
        bool locked;
};

#endif //PROYECTO_JUEGO_ROOM_H