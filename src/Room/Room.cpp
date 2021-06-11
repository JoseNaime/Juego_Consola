// Un proyecto elaborado por: 
// Andrés Alejandro Guzmán González - A01633819
// José Pablo Naime García - A01367610
// © 2021 José Pablo Naime García Andrés Alejandro Guzmán González All Rights Reserved

#include "Room.h"
#include "./../Game/Game.h"

Room::Room(){

}

Room::Room( int roomId_, string nam,string ini, Enemy* e, int x, int y, bool lock){
  roomId = roomId_;
  name = nam;
  initDescriptionUrl = ini;
  enemy = e;
  posX = x;
  posY = y;
  locked = lock;
}

Room::Room( int roomId_, string nam,string ini, vector<Item*> items_, Enemy* e, int x, int y, bool lock){
  roomId = roomId_;
  name = nam;
  initDescriptionUrl = ini;
  for (int i = 0; i < items_.size(); i++){
    items.push_back(items_[i]);
  }
  enemy = e;
  posX = x;
  posY = y;
  locked = lock;
}

int Room::getRoomId() const{
  return roomId;
}

void Room::setRoomId(int i){
  roomId = i;
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

Enemy* Room::getEnemy() const{
  return enemy;
}

void Room::setEnemy(Enemy* e){
  enemy = e;
}

void Room::deleteItem(Item *item){
    items.erase(remove(items.begin(), items.end(), item));
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
  cout << "---------- " << name << " ----------" << endl;
  Game::printTextFile(initDescriptionUrl, 1.5, false, false);
  if (items.size() > 0){
    cout << "\nEn el cuarto se encuentran los siguietes items: " << endl;
    for(Item* item : items){
      Game::addDelay(1); // Delay between text line
      cout << "- " << item->getName() << endl;
    }
  }
}

void Room::printInfo(float f){ // Se imprime toda la informacion del cuarto 
  Game::clearScreen(0);
  cout << "---------- " << name << " ----------" << endl;
  Game::printTextFile(initDescriptionUrl, f, false, false);
  if (items.size() > 0){
    cout << "\nEn el cuarto se encuentran los siguietes items: " << endl;
    for(Item* item : items){
      Game::addDelay(1); // Delay between text line
      cout << "- " << item->getName() << endl;
    }
  }
}
