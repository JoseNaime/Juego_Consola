// Un proyecto elaborado por: 
// Andrés Alejandro Guzmán González - A01633819
// José Pablo Naime García - A01367610
// © 2021 José Pablo Naime García Andrés Alejandro Guzmán González All Rights Reserved

#include "Room.h"
#include "./../Game/Game.h"

Room::Room(){

}

Room::Room(string nam, string ini, Item** items_, int x, int y, bool lock){
  name = nam;
  initDescriptionUrl = ini;
  for (int i = 0; i < sizeof(items_); i++){
    items[i] = items_[i];
  }
  posX = x;
  posY = y;
  locked = lock;
}

string Room::getName() const{
  return name;
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

array<int,2> Room::getPosition() const{
  array<int,2> pos = {posX, posY};
  return pos;
}

void Room::setPosition(int p[2]){
  posX = p[0];
  posY = p[1];
}

bool Room::getLocked() const{
  return locked;
}

void Room::setPlayerIsIn(bool p){
  playerIsIn = p;
}

bool Room::getPlayerIsIn() const{
  return playerIsIn;
}

void Room::deleteItem(Item *item){
    for (int i = 0; i < sizeof(items); i++)
    {
        if (items[i] == item)
        {
            items[i] = nullptr;
            break;
        }
    }
}

bool Room::itemExists(string name_){
  name_ = boost::algorithm::to_lower_copy(name_);
  for (Item* item:items){
    if (boost::algorithm::to_lower_copy(item->getName()) == name_){
      return true;
    }
  }
  return false;
}

Item* Room::getItem(string name_){
  name_ = boost::algorithm::to_lower_copy(name_);
  if (itemExists(name_)){
    for (Item* item : items){
      if (boost::algorithm::to_lower_copy(item->getName()) == name_){
      return item;
      }
    }
  }
  return nullptr;
}

void Room::printInfo(){ // Se imprime toda la informacion del cuarto
  Game::clearScreen(0);
  cout << name << endl;
  Game::printTextFile(initDescriptionUrl, 1.5, false, false);
  cout << "\nEn el cuarto se encuentran los siguietes items: " << endl;
  for(Item* item: items){
    Game::addDelay(1); // Delay between text line
    cout << "- " << item->getName() << endl;
  }
  

}
