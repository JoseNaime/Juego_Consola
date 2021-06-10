#include "Room.h"
#include "./../Game/Game.h"

Room::Room(){

}

Room::Room(string nam, string ini, Item *items_[], int x, int y, bool lock){
  name = nam;
  initDescriptionUrl = ini;
  for(int i = 0; i < 3; i++){
    items[i] = items_[i];
  }
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

string Room::getInitDescriptionUrl() const{
  return initDescriptionUrl;
}

void Room::setInitDescriptionUrl(string i){
  initDescriptionUrl = i;
}

int* Room::getPosition() const{
  int pos[2] = {posX, posY};
  return pos;
}

void Room::setPosition(int p[2]){
  posX = p[0];
  posY = p[1];
}

bool Room::getLocked(){
  return locked;
}

void Room::printInfo(){ // Se imprime toda la informacion del cuarto
  Game::clearScreen(0);
  cout << name << endl;
  Game::printTextFile(initDescriptionUrl, 1.5);
  cout << "\nEn el cuarto se encuentran los siguietes items: " << endl;
  for(int i = 0; i < 3; i++){
    Game::addDelay(1); // Delay between text line
    cout << "- " << items[i]->getName() << endl;
  }
  

}
