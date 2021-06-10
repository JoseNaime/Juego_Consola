#define MENU_URL "./ConsoleUI/Menu"
#define CONTROLS_URL "./ConsoleUI/Controls"
#define INSTRUCTIONS_URL "./ConsoleUI/Instructions"
#define INTRO_URL "./ConsoleUI/Intro"

#include <fstream>
#include <iostream>
#include <unistd.h>
#include <cctype>
#include <exception>

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
  *player->getInventory() += new Item("Llave Final", "Esta llave te ayuda a abrir la puerta final", KEY, 1);
  try{
      Item* items[3] = {
    new Item("Llave Final", "Esta llave te ayuda a abrir la puerta final", KEY, 1),
    new Item("Espada", "Esta espada parece oxidada, pero servira de algo", WEAPON, 2),
    new Item("Palo de madera", "Un simple palo de madera...", USELESS, 2)
    };

  Room* rooms[4] = {
    new Room("Cuarto 1301", "./Levels/Dialogs/Room1_D", items, 7, 14, false),
    new Room("Cuarto 1302", "./Levels/Dialogs/Room2_D", items, 7, 10, false),
    new Room("Cuarto 1303", "./Levels/Dialogs/Room3_D", items, 7, 6, false),
    new Room("Cuarto 1304", "./Levels/Dialogs/Room4_D", items, 7, 2, false)
    };

    map->setRooms(rooms);
    player->setMap(map);
  }catch(string e){
    cout << "Error al cargar valores iniciales en el juego: " << e << endl;
  }catch(overflow_error e){
    cout << "Overflow en valores iniciales: " << e.what() << endl;
  }

  try{
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
    clearScreen(0);
    printTextFile(INTRO_URL, 2, true);

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
  switch (tolower(input)){
    case 'd':
      this->player->moveTo(RIGHT);
    break;
    case 'a':
      this->player->moveTo(LEFT);
    break;
    case 'w':
      this->player->moveTo(UP);
    break;
    case 's':
      this->player->moveTo(DOWN);
    break;

    case 'i':
     this->player->getInventory()->printInventory();
    break;

    case 'q':
      this->gameState = END;
    break;
  }
}

void Game::logic(){
  cout << player->getPosX() << " | " << player->getPosY() << endl;

}

void Game::display(){
    clearScreen(0);
    this->map->print();
    printTextFile(CONTROLS_URL, 0);
}

void Game::clearScreen(float delay){
    addDelay(delay);
    if (system("CLS")) system("clear");
}

void Game::addDelay(float d){
  usleep(d * 100000);
}

void Game::printTextFile(string url, float delay){
  try{
    ifstream file(url);
    if (file.is_open()){
        string line;
        while(getline(file,line)){
            cout << line << endl;
            
            addDelay(delay); // Delay between text line
        }
        file.close();
    }
  }catch(string e){
      cout << "Error al imprimir archivo de texto: " + e;
  }
}

void Game::printTextFile(string url, float delay, bool enterToContinue){
  try{
    ifstream file(url);
    if (file.is_open()){
        string line;
        while(getline(file,line)){
            cout << line << endl;
            addDelay(delay); // Delay between text line
        }
        file.close();
    }
    cout << "\n\nIngrese cualquier valor para continuar: ";
    string aux;
    cin >> aux;
  }catch(string e){
      cout << "Error al imprimir archivo de texto: " + e;
  }
}