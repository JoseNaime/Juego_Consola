// Un proyecto elaborado por: 
// Andrés Alejandro Guzmán González - A01633819
// José Pablo Naime García - A01367610
// © 2021 José Pablo Naime García Andrés Alejandro Guzmán González All Rights Reserved

#ifndef PROYECTO_JUEGO_INVENTORY_H
#define PROYECTO_JUEGO_INVENTORY_H

#include <vector>
#include <iostream>
#include "./../Item/Item.h"
using namespace std;

class Inventory{
    public:
    Inventory(); //Constructor sin parametros
    Inventory(int, vector<Item*>); //Constructor con parametros

    void addItem(Item*); //Metodo para agregar un Item al inventario
    void removeItem(Item*); //Metodo para eliminar un Item del inventario
    void printInventory();  // Imprime el inventario

    vector<Item*> getItems() const; // Regresa un vector con los Items del inventario
    int getSpace() const; //Regresa el espacio máximo del inventario
    void setItems(vector<Item*>); // Asigna un vector con los Items al inventario
    void setSpace(int); //Asigna el espacio máximo del inventario
    bool itemExists(string);
    Item* getItem(string);

    // SOBRECARGA DE OPERADORES

    void operator-=(Item*); // Quita un Item del inventario del jugador
    void operator+=(Item*); // Agrega un item del inventario de jugador

    private:
    int currentSpace = 0;
    int space;
    vector<Item*> items;

};

#endif