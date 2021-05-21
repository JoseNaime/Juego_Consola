//
// Created by Jose Naime on 14/05/21.
//
#define MENU_URL "./ConsoleUI/Menu"
#define CONTROLS_URL "./ConsoleUI/Controls"
#define INSTRUCTIONS_URL "./ConsoleUI/Instructions"
#define INTRO_URL "./ConsoleUI/Intro"

#include <fstream>
#include <iostream>
#include <unistd.h>

#include "Game.h"


Game::Game(Map* map, Player* player) {
    this->map = map;
    this->player = player;
}
void Game::setGameState(GAME_STATE gameState){
    this->gameState = gameState;
}

GAME_STATE Game::getGameState() const {
    return this->gameState;
}

void Game::start() {
    printTextFile(MENU_URL, 2); // Print Menu

    int option;
    cin >> option;

    switch(option){
        case 1:
            setGameState(IN_GAME);
            gameLoop();
        break;
        case 2:
            printTextFile(INSTRUCTIONS_URL, 2);
            char a;
            cin >> a;
            if (a) start();
            break;
        case 3:
            setGameState(END);
            cout << "Gracias por jugar, vuelve pronto" << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
            start();
            break;
    }
}

void Game::gameLoop() {
    printTextFile(INTRO_URL, 2);
    display();
    /*while (this->gameState == IN_GAME){
        display();
        getInput();
    }*/
}

void Game::getInput(){

}

void Game::display(){
    this->map->print();
    printTextFile(CONTROLS_URL, 0);
}

void Game::printTextFile(string url, float delay){
    ifstream file(url);
    if (file.is_open()){
        string line;
        while(getline(file,line)){
            cout << line << endl;
            usleep(delay * 100000); // Delay between text line
        }
        file.close();
    }
}