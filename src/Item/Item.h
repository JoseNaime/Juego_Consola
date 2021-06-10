#ifndef PROYECTO_JUEGO_ITEM_H
#define PROYECTO_JUEGO_ITEM_H
#include "string"
using namespace std;

enum ITEM_TYPE {KEY, WEAPON, DEFENCE, USELESS};
class Item{
  public:
    Item();
    Item(string, string, ITEM_TYPE, int);

    string getName() const;
    string getDescription() const;
    ITEM_TYPE getItemType() const;
    int getSize() const;
    void setName(string);
    void setDescription(string);
    void setItemType(ITEM_TYPE);
    void setSize(int);

  private:
    string name, description;
    ITEM_TYPE itemType;
    int size;
};

#endif