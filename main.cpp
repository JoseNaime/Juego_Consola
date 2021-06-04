#include <iostream>

#include "./src/Game/Game.h"

int main() {
    string name;
    cout << "Ingresa tu nombre" << endl;
    cin >> name;

    Game game = Game(new Map("./Levels/Map"), new Player(name, 3, 1, 8, 14));
    game.start();

    return 0;
}
