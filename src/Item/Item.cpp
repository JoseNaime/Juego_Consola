#include "Item.h"

Item::Item(){
  name = "Vacio";
  description = "Espacio de inventario";
  itemType = USELESS;
  size = 0;
}

Item::Item(string name_, string description_, ITEM_TYPE itemType_, int size_){
  name = name_;
  description = description_;
  itemType = itemType_;
  size = size_;
}

string Item::getName() const{
  return name;
}

string Item::getDescription() const{
  return description;
}

ITEM_TYPE Item::getItemType() const{
  return itemType;
}

int Item::getSize() const{
  return size;
}

void Item::setName(string s){
  name = s;
}

void Item::setDescription(string s){
  description = s;
}

void Item::setItemType(ITEM_TYPE i){
  itemType = i;
}

void Item::setSize(int s){
  size = s;
}