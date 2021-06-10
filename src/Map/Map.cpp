//
//
#include <iostream>
#include <fstream>

#include "Map.h"

using namespace std;

Map::Map() {
    stringToMatrix("./Levels/Map");
}

Map::Map(string mapUrl) {
    stringToMatrix(mapUrl);
}

void Map::stringToMatrix(string url) {
  try{
    ifstream file(url);
    if (file.is_open()) { // Load File
        string line;
        int j = 0;

        while ( getline (file,line) )
        {
            for (int i = 0; i <= 12; i++){
                mapArr[j][i]= line[i];
            }
            j++;
        }
        file.close();
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
  for (int i = 0; i < sizeof(rooms); i++){
    auxVec.push_back(rooms[i]);
  }
  return auxVec;
}

void Map::setRooms(Room *rooms_[4]){
  for(int i = 0; i < 4; i++){
    rooms[i] = rooms_[i];
  }
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