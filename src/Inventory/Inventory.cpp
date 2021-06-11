// Un proyecto elaborado por: 
// Andrés Alejandro Guzmán González - A01633819
// José Pablo Naime García - A01367610
// © 2021 José Pablo Naime García Andrés Alejandro Guzmán González All Rights Reserved

#include "../Game/Game.h"
#include "Inventory.h"

Inventory::Inventory() {
  space = 6;
}

Inventory::Inventory(int space_, vector<Item*> items_){
  space = space_;
  items = items_;
  for (int i = 0; i < items_.size(); i++){
    addItem(new Item());
  }
}

void Inventory::addItem(Item * item_){
  if (currentSpace + item_->getSize() <= space){
    items.push_back(item_);
    currentSpace += item_->getSize();
    cout << "Se ha agregado a tu inventario: " << item_->getName() << endl;
  }else{
    cout << "No tienes espacio suficiente para guardar " << item_->getName() << endl;
  }
}

void Inventory::removeItem(Item *item){
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i] == item)
        {
            items.erase(items.begin() + i);
            break;
        }
    }
}

void Inventory::printInventory(bool enterToContinue_){
  if (items.size() <= 0){
    cout << "\nEl inventario esta vacio, busca algunos objetos" << endl;
  }else{
    cout << "Inventario: " << endl;
    for (Item* item : items){
      cout << "- " << item->getName() << " : " << item->getDescription() << endl;
    }
  }
  if (enterToContinue_){
  Game::enterToContinue();
  }
}

vector<Item*> Inventory::getItems() const{
  return items;
}

void Inventory::setItems(vector<Item *> items_){
  items = items_;
}

void Inventory::setSpace(int size_){
  space = size_;
}

int Inventory::getSpace() const{
  return space;
}

int Inventory::getCurrentSpace() const{
  return currentSpace;
}

bool Inventory::itemExists(string name_){
  name_ = boost::algorithm::to_lower_copy(name_);
  for (Item* item:items){
    if (boost::algorithm::to_lower_copy(item->getName()) == name_){
      return true;
    }
  }
  return false;
}

Item* Inventory::getItem(string name_){
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

void Inventory::operator-=(Item* item_){
  removeItem(item_);
}

void Inventory::operator+=(Item* item_){
  addItem(item_);
}