#include <iostream>
#include "string"
#include "./src/Game/Game.h"

using namespace std;

int main() {

    //game.update();
    string name;
    cout << "Ingresa tu nombre" << endl;
    cin >> name;

    Player* player = new Player(name, 3, 1, 8, 14);
    Map map = Map("./../Levels/Room1");
    Game game = Game(&map, player);

    game.start();

    return 0;
}
