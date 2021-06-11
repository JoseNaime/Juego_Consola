// Un proyecto elaborado por: 
// Andrés Alejandro Guzmán González - A01633819
// José Pablo Naime García - A01367610
// © 2021 José Pablo Naime García Andrés Alejandro Guzmán González All Rights Reserved

#ifndef PROYECTO_JUEGO_ENEMY_H
#define PROYECTO_JUEGO_ENEMY_H

// La clase Enemy es una clase derivada de la clase Character

#include "../Character/Character.h"
#include "../Item/Item.h"
#include <iostream>

using namespace std;

class Enemy: public Character{
    public:
        Enemy(); // Constructor sin parametros
        Enemy(string, int, int, string, Item*); // Constructor getcon parametros
        string getEnemyDescriptUrl() const; // Regresa la descripcion del enemigo
        void setEnemyDescriptUrl(string); // Asigna la descripcion del enemigo
        Item* getEnemyItem(); // Regresa el reward o item que tiene el enemigo
        void setEnemy(Item*); // Asigna el reward o item que tiene el enemigo

        void attack(Character*);
    private:
        string enemyDescriptUrl;
        Item* item = nullptr;
};

#endif // PROYECTO_JUEGO_ENEMY_H