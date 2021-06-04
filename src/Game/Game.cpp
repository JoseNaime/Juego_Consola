#define MENU_URL "./ConsoleUI/Menu"
#define CONTROLS_URL "./ConsoleUI/Controls"
#define INSTRUCTIONS_URL "./ConsoleUI/Instructions"
#define INTRO_URL "./ConsoleUI/Intro"

#include <fstream>
#include <iostream>
#include <unistd.h>
#include <cctype>

#ifdef __cplusplus__
  #include <cstdlib>
#else
  #include <stdlib.h>
#endif

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
  try{
    string name;
    cout << "Ingresa tu nombre" << endl;
    cin >> name;
    printTextFile(MENU_URL, 2); // Print Menu

    int option;
    cin >> option;

    switch(option){
        case 1: // Play game
            setGameState(IN_GAME);
            gameLoop();
        break;
        case 2: // Introduccion
            printTextFile(INSTRUCTIONS_URL, 2);
            char a;
            cin >> a;
            if (a) start();
            break;
        case 3: // Salir del juego
            setGameState(END);
            cout << "Gracias por jugar, vuelve pronto" << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
            start();
            break;
    }
    }catch(string e){
      cout << "Error al iniciar el juego: " + e;
    }
}

void Game::gameLoop() {
    try{
    printTextFile(INTRO_URL, 2);
    while (this->gameState == IN_GAME){
        display();
        getInput();
        logic();
    }
    }catch(string e){
      cout << "Error en el loop del juego: " + e;
    }
}

void Game::getInput(){ // Controles de jugador
  char input;
  cin >> input;
  switch (input){
    case 'd':
      this->player->moveTo(RIGHT, *map);
    break;
    case 'a':
      this->player->moveTo(LEFT, *map);
    break;
    case 'w':
      this->player->moveTo(UP, *map);
    break;
    case 's':
      this->player->moveTo(DOWN, *map);
    break;

    case 'q':
      this->gameState = END;
    break;
  }

}

void Game::logic(){

  std::cout << player->getPosX() << " | " << player->getPosY() << endl;
}

void Game::display(){
    if (system("CLS")) system("clear");
    this->map->print();
    printTextFile(CONTROLS_URL, 0);
}

void Game::printTextFile(string url, float delay){
  try{
    ifstream file(url);
    if (file.is_open()){
        string line;
        while(getline(file,line)){
            cout << line << endl;
            
            usleep(delay * 100000); // Delay between text line
        }
        file.close();
    }
  }catch(string e){
      cout << "Error al imprimir archivo de texto: " + e;
  }
}