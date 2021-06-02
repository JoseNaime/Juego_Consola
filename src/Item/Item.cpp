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