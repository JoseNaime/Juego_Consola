// Un proyecto elaborado por: 
// Andrés Alejandro Guzmán González - A01633819
// José Pablo Naime García - A01367610
// © 2021 José Pablo Naime García Andrés Alejandro Guzmán González All Rights Reserved

#ifndef PROYECTO_JUEGO_ITEM_H
#define PROYECTO_JUEGO_ITEM_H
#include "string"
using namespace std;

// Enumerator - Tipo de dato que nos permitie declarar una serIe de constantes. En este caso las constantes definidas son los tipos de ITEMS (Referencia disponible en el archivo pdf)
enum ITEM_TYPE {KEY, WEAPON, DEFENCE, USELESS};

class Item{
  public:
    Item(); // Constructor sin parametros
    Item(string, string, ITEM_TYPE, int); //Constructor con parametros

    string getName() const; //Regresa el nombre del Item
    string getDescription() const; //Regresa la descripcion del Item
    ITEM_TYPE getItemType() const; //Regresa el tipo de Item
    int getSize() const; //Regresa el tamaño que el Item ocupara en el inventario 
    void setName(string); //Asigna el nombre del Item
    void setDescription(string); //Asigna la descripcion del item
    void setItemType(ITEM_TYPE); // Asigna el tipo de Item
    void setSize(int); //Asigna la cantidad de espacio que el item opucara en el inventario del jugador.

  private:
    string name, description;
    ITEM_TYPE itemType;
    int size;
};

#endif