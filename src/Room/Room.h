#ifndef PROYECTO_JUEGO_ROOM_H
#define PROYECTO_JUEGO_ROOM_H

#include "string"

class Room {
    public:
        Room();
        Room(int, int);
    private:
        string name, initDescription;
        int position[2];

};


#endif //PROYECTO_JUEGO_ROOM_H
