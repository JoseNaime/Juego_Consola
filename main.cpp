#include <iostream>
#include "./src/Game/Game.h"

int main() {

    //game.update();

    Player player = Player(8,14);
    Map map = Map("./../Levels/Room1");
    Game game = Game(&map, &player);

    game.start();

    return 0;
}
