// Un proyecto elaborado por: 
// Andrés Alejandro Guzmán González - A01633819
// José Pablo Naime García - A01367610
// © 2021 José Pablo Naime García Andrés Alejandro Guzmán González All Rights Reserved

#ifndef PROYECTO_JUEGO_ROOM_H
#define PROYECTO_JUEGO_ROOM_H

#include <iostream>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <array>

#include "string"
#include "./../Item/Item.h"
#include "../Enemy/Enemy.h"

using namespace std;

class Room {
    public:
        Room(); // constructor sin parametros
        Room(int, string, string, Enemy*, int, int, bool); // Constructor
        Room(int, string, string, vector<Item*>, Enemy*, int, int, bool); // Constructor(nombre, initDescriptionUrl, arreglo con items del cuarto, posicion x, posicion y, el cuarto esta cerrado?)
    
        int getRoomId() const;
        void setRoomId(int);
        string getName() const; // Regresa el nombre del cuarto.
        void setName(string); // Asigna el nombre del cuarto
        string getInitDescriptionUrl() const; // Regreasa la descripcion del cuarto.
        void setInitDescriptionUrl(string); // Asigna el url de la descripcion del cuarto
        
        array<int,2>  getPosition() const; // Regresa arreglo con la posicion del cuarto
        void setPosition(int[2]);  // Asigna la posicion del cuarto por un arreglo de ints
        void setPosition(int, int); // Asigna la posicion por medio de 'x' y 'y'
        bool getLocked()const; // Checa si el cuarto esta bloqueado
        void setLocked(bool); // Asigna si el cuarto esta bloqueado o no
        bool getPlayerIsIn() const; // Checa si el jugador se encuentra en esta cuarto
        void setPlayerIsIn(bool); // Asigna si el jugador esta en el cuarto
        Enemy* getEnemy() const;
        void setEnemy(Enemy*);

        void deleteItem(Item*);
        bool itemExists(string); // Checa si un item existe en el cuarto
        Item* getItem(string); // Regresa un item despues de checar si este existe
        void printInfo();
        void printInfo(float);
    private:
        int roomId, posX, posY;
        bool locked, playerIsIn = false;
        string name, initDescriptionUrl;
        vector<Item*> items;
        Enemy* enemy;

};

#endif //PROYECTO_JUEGO_ROOM_H