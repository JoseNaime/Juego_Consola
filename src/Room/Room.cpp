#include "Room.h"

Room::Room(){

}

Room::Room(string nam, string ini, Item* items[3], int x, int y, bool lock){
  name = nam;
  initDescription = ini;
  items = items;
  posX = x;
  posY = y;
  locked = lock;
}

string Room::getName() const{
  return name;
}

int Room::getPosX() const{
  return posX;
}

int Room::getPosY() const{
  return posY;
}

void Room::setName(string n){
  name = n;
}

void Room::setInitDescription(string i){
  initDescription = i;
}

void Room::setPosition(int p[2]){
  posX = p[0];
  posY = p[1];
}

void Room::printInfo(){ // Se imprime toda la informacion del cuarto

}
