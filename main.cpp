// Un proyecto elaborado por: 
// Andrés Alejandro Guzmán González - A01633819
// José Pablo Naime García - A01367610
// © 2021 José Pablo Naime García Andrés Alejandro Guzmán González All Rights Reserved

#include <iostream>

#include "./src/Game/Game.h"
#include "./src/Player/Player.h"
#include "./src/Map/Map.h"



int main() {
    string name;
    cout << "Ingresa tu nombre" << endl;
    cin >> name;

    Game* game = new Game(new Map("./Levels/Map"), new Player(name, 3, 1, 8, 14));
    game->start();

    return 0;
}
