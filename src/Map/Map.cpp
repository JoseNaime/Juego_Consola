// Un proyecto elaborado por: 
// Andrés Alejandro Guzmán González - A01633819
// José Pablo Naime García - A01367610
// © 2021 José Pablo Naime García Andrés Alejandro Guzmán González All Rights Reserved

#include <iostream>
#include <fstream>

#include "Map.h"

using namespace std;

// La funcion de la clase Map es generar una matriz para imprimir el mapa a consula.

Map::Map() {
    stringToMatrix("./Levels/Map");
}

Map::Map(string mapUrl) {
    stringToMatrix(mapUrl);
}

void Map::stringToMatrix(string url) {
  try{
    ifstream file(url);
    if (file.is_open()) { // Checa si el codigo esta abierto
        string line;
        int j = 0;

        while ( getline (file,line) ) // Mientras siga obteniendo contenido del archivo...
        {
            for (int i = 0; i <= 12; i++){
                mapArr[j][i]= line[i]; // Agrega ese character a nuestra matriz
            }
            j++;
        }
        file.close(); // Cierra el archivo
    }
  }catch(string e){
    cout << "Error al cargar mapa como matriz: " + e;
  }
}

char Map::getPosition(int i, int j) const {
    return this->mapArr[j][i];
}

void Map::setPosition(int i, int j, char v) {
    this->mapArr[j][i] = v;
}

vector<Room*> Map::getRooms(){
  vector<Room*> auxVec;
  for (Room* room : rooms){
    auxVec.push_back(room);
  }
  return auxVec;
}

void Map::setRooms(Room** rooms_){
  try{
    for(int i = 0; i < 4; i++){
      rooms[i] = rooms_[i];
    }
  }catch(bad_alloc e){
    cout << "Error al asignar valores en la memoria: " << e.what() << endl;
  }
}

Room* Map::playerRoom(){
  for(Room* room : rooms){
    cout << room->getName() << endl;
    if (room->getPlayerIsIn()){
      return room;
    }
  }
  cout << "No se encontro ningun cuarto";
  return nullptr;
}

bool Map::canMoveToPosition(int, int){
  return true;
}

void Map::print() {
    for (auto & line : mapArr) {
        for (char val : line) {
            cout << ' ' << val;
        }
        cout << endl;
    }
}