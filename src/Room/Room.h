#ifndef PROYECTO_JUEGO_ROOM_H
#define PROYECTO_JUEGO_ROOM_H

#include "string"

class Room {
    public:
        Room();
        Room(int, int);

        string getName() const;
        string getInitDescription() const();
        int[] getPosition() const;

        void setName(string);
        void setInitDescription(string);
        void setPosition(int[2]);
        void setPosition(int, int);
        void printInfo();
    private:
        string name, initDescription;
        int position[2];

};


#endif //PROYECTO_JUEGO_ROOM_H
