//
// Created by Jose Naime on 14/05/21.
//

#ifndef PROYECTO_JUEGO_MAP_H
#define PROYECTO_JUEGO_MAP_H

#include "string"
using namespace std;

class Map {
    public:
        Map();
        Map(string);
        void stringToMatrix(string);
        char getPosition(int, int) const;
        void setPosition(int, int, char);
        void print();
    private:
        char mapArr[10][10]{};
};


#endif //PROYECTO_JUEGO_MAP_H
