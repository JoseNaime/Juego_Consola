#include "Player.h"

Player::Player() {
    posX = 1;
    posY = 1;
}

Player::Player(string n, int liv, int dam, int x, int y):Character(n, liv, dam){
    posX = x;
    posY = y;
    inventory = new Inventory();
}

void Player::moveTo(DIRECTION dir){
    int move [2] = {0,0};
    switch (dir){
        case RIGHT:
            move[0] = 1;
            break;
        case LEFT:
            move[0] = -1;
            break;
        case UP:
            move[1] = -1;
            break;
        case DOWN:
            move[1] = 1;
            break;
        default:
            cout << "Direccion Invalida" << endl;
    }
    if (move[0] != 0 || move[1] != 0){
        char posToMove = map->getPosition(getPosX() + move[0], getPosY() + move[1]);
        switch (posToMove){
          case '.':{
            char currPosChar = map->getPosition(getPosX(), getPosY());
            setPos(getPosX() + move[0], getPosY() + move[1]);
            map->setPosition(getPosX() - move[0], getPosY() - move[1], '.');
            map->setPosition(getPosX(), getPosY(), 'P');
            break;
          }
          case '|':{
            vector<Room*> rooms = map->getRooms();
            for (int i = 0; i < sizeof(map->getRooms()); i++){
              Room* currentRoom = rooms[i];
              if (currentRoom->getPosX() == getPosX() + move[0] && currentRoom->getPosY() == getPosY() + move[1]){
                if (currentRoom->getLocked()){
                  cout << "El " << currentRoom->getName() << " esta cerrado, deberas buscar una forma de abrirlo" << endl;
                }
                currentRoom->printInfo();
                break;
              }
            }
          break;
          }
          default:

          break;
        }
    }
}

int Player::getPosX() const{
    return posX;
}

int Player::getPosY() const{
    return posY;
}

Inventory* Player::getInventory() const{
    return inventory;
} 

void Player::setPos(int x, int y){
    posX = x;
    posY = y;
}

void Player::setPosX(int x){
    posX = x;
}

void Player::setPosY(int y){
    posY = y;
}

void Player::setInventory(Inventory* inv){
  inventory = inv;
}

void Player::setMap(Map* map_){
  map = map_;
}