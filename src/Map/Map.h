#ifndef PROYECTO_JUEGO_MAP_H
#define PROYECTO_JUEGO_MAP_H

#include "string"
using namespace std;

class Map {
    public:
        Map();
        Map(string);
        char getPosition(int, int) const;
        void setPosition(int, int, char);
        void stringToMatrix(string); // Crea matriz a partir de un archivo
        bool canMoveToPosition(int, int); // Checa si la ubicacion es valida
        void print(); // Imprime el mapa
    private:
        char mapArr[17][12]{}; // [alto][ancho]
};


#endif //PROYECTO_JUEGO_MAP_H
