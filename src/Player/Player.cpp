// Un proyecto elaborado por: 
// Andrés Alejandro Guzmán González - A01633819
// José Pablo Naime García - A01367610
// © 2021 José Pablo Naime García Andrés Alejandro Guzmán González All Rights Reserved

#include "Player.h"
#include "../Game/Game.h"

Player::Player() {
    posX = 1;
    posY = 1;
}

Player::Player(string n, int liv, int dam, int x, int y):Character(n, liv, dam){
    posX = x;
    posY = y;
    inventory = new Inventory();
}

PLAYER_CONTEXT Player::moveTo(DIRECTION dir){
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
            return NAVIGATE;
          }
          case '|':{
            vector<Room*> rooms = map->getRooms();
            for (Room* room : rooms){
              if (room->getPosition()[0] == getPosX() + move[0] && room->getPosition()[1] == getPosY() + move[1]){
                if (room->getLocked()){
                  cout << "El " << room->getName() << " esta cerrado, deberas buscar una forma de abrirlo" << endl;
                  Game::enterToContinue();
                  return NAVIGATE;
                  break;
                }else{
                  room->setPlayerIsIn(true);
                  room->printInfo();
                  
                  return IN_ROOM;
                  break;
                }
              }
            }
          return NAVIGATE;
          }
        }
    }
    return NAVIGATE;
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