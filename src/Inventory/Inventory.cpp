#include "Inventory.h"

Inventory::Inventory() {
  space = 3;
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

void Inventory::printInventory(){
  if (items.size() <= 0){
    cout << "El inventario esta vacio, busca algunos objetos" << endl;
  }else{
    cout << "Inventario: " << endl;
    for (int i = 0; i < items.size(); i++){
      cout << "- " << items[i]->getName() << " : " << items[i]->getDescription() << endl;
    }
  }
  string aux;
  cin >> aux;
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

void Inventory::operator-=(Item* item_){
  removeItem(item_);
}

void Inventory::operator+=(Item* item_){
  addItem(item_);
}