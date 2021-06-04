#include "Item.h"

Item::Item(){
  name = "Desconocido";
  description = "Un objeto cualquiera";
  itemType = USELESS;
  size = 1;
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

void Item::setName(string s){
  name = s;
}

void Item::setDescription(string s){
  description = s;
}

void Item::setItemType(ITEM_TYPE i){
  itemType = i;
}