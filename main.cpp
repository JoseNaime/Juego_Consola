#include <iostream>

#include "./src/Game/Game.h"

#include <iostream>

int main() {

    //game.update();

    Player player = Player(1,1);
    Map map = Map("./../Levels/Room1");
    Game game = Game(&map, &player);

    game.start();


    return 0;
}
