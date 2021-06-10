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
        char getPosition(int, int) const;
        void setPosition(int, int, char);
        vector<Room*> getRooms();
        void setRooms(Room* rooms_[5]);
        void stringToMatrix(string); // Crea matriz a partir de un archivo
        bool canMoveToPosition(int, int); // Checa si la ubicacion es valida
        void print(); // Imprime el mapa
    private:
        char mapArr[17][12]{}; // [alto][ancho]
        Room* rooms[4]{};
};


#endif //PROYECTO_JUEGO_MAP_H
