//
// Created by Jose Naime on 14/05/21.
//
#include <iostream>
#include <fstream>

#include "Map.h"

using namespace std;

Map::Map() {
    stringToMatrix("./Levels/Room1");
}

Map::Map(string mapUrl) {
    stringToMatrix("./Levels/Room1");
}

void Map::stringToMatrix(string url) {
    ifstream file(url);
    if (file.is_open()) { // Load File
        string line;
        int j = 0;

        while ( getline (file,line) )
        {
            for (int i = 0; i <= 10; i++){
                mapArr[j][i]= line[i];
            }
            j++;
        }
        file.close();
    }
}

char Map::getPosition(int i, int j) const {
    return this->mapArr[i][j];
}

void Map::setPosition(int i, int j, char v) {
    this->mapArr[i][j] = v;
}

void Map::print() {
    for (auto & line : mapArr) {
        for (char val : line) {
            cout << ' ' << val;
        }
        cout << endl;
    }
}


