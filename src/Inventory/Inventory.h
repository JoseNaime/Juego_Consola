#ifndef PROYECTO_JUEGO_INVENTORY_H
#define PROYECTO_JUEGO_INVENTORY_H

#include <vector>
#include <iostream>
#include "./../Item/Item.h"
using namespace std;

class Inventory{
  public:
  Inventory();
  Inventory(int, vector<Item*>);

  void addItem(Item*);
  void removeItem(Item*);
  void printInventory();

  vector<Item*> getItems() const;
  int getSpace() const;
  void setItems(vector<Item*>);
  void setSpace(int);

  void operator-=(Item*);
  void operator+=(Item*);

  private:
  int currentSpace = 0;
  int space;
  vector<Item*> items;

};

#endif