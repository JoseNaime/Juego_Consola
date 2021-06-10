// Un proyecto elaborado por: 
// Andrés Alejandro Guzmán González - A01633819
// José Pablo Naime García - A01367610
// © 2021 José Pablo Naime García Andrés Alejandro Guzmán González All Rights Reserved

#ifndef PROYECTO_JUEGO_MAP_H
#define PROYECTO_JUEGO_MAP_H

#include <vector>
#include "string"

#include "../Room/Room.h"
using namespace std;

class Map {
    public:
        Map();
        Map(string);

        char getPosition(int, int) const; // Regresa el character en esa posicion del mapa
        void setPosition(int, int, char);
        vector<Room*> getRooms(); // regresa todos los cuartos que tiene el mapa
        void setRooms(Room* rooms_[5]);

        void stringToMatrix(string); // Crea matriz a partir de un archivo
        bool canMoveToPosition(int, int); // Checa si la ubicacion es valida
        Room* playerRoom(); // Checa si el jugador esta en un cuarto y lo regresa
        void print(); // Imprime el map
    private:
        char mapArr[17][12]{}; // [alto][ancho]
        Room* rooms[4]{};
};


#endif //PROYECTO_JUEGO_MAP_H
