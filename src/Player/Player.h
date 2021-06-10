// Un proyecto elaborado por: 
// Andrés Alejandro Guzmán González - A01633819
// José Pablo Naime García - A01367610
// © 2021 José Pablo Naime García Andrés Alejandro Guzmán González All Rights Reserved

#ifndef PROYECTO_JUEGO_PLAYER_H
#define PROYECTO_JUEGO_PLAYER_H

//La clase Player es una clase derivada de la clase Character

#include <iostream>
#include <vector>

#include "../Character/Character.h"
#include "../Map/Map.h"
#include "../Inventory/Inventory.h"
using namespace std;

enum DIRECTION {LEFT, RIGHT, UP, DOWN};
enum PLAYER_CONTEXT {IN_ROOM, COMBAT, NAVIGATE};

class Player : public Character {
    public:
        Player(); // Constructor sin parametros
        Player(string, int, int, int, int); // Costructor con parámetros name, lives, damage, x, y
        PLAYER_CONTEXT moveTo(DIRECTION); // Funcion para definr que esta haceindo el jugador

        int getPosX() const; // Regresa la posicion x del jugador
        int getPosY() const; // Regresa la posicion y del jugador
        Inventory* getInventory() const; // Regresa el inventario del jugador
        void setPos(int, int); // Asigna los valores X y Y de la posicion del jugador
        void setPosX(int); // Asigna el valor X de la posicion del jugador
        void setPosY(int); // Asigna el valor Y de la posicion del jugador
        void setInventory(Inventory*); // Asigna el inventario del jugador
        void setMap(Map*); //Asignar la referencia del mapa al jugador

    private:
        int posX, posY;
        Inventory* inventory;
        Map* map;
};
#endif //PROYECTO_JUEGO_PLAYER_H