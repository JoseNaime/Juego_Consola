// Un proyecto elaborado por: 
// Andrés Alejandro Guzmán González - A01633819
// José Pablo Naime García - A01367610
// © 2021 José Pablo Naime García Andrés Alejandro Guzmán González All Rights Reserved

#define MENU_URL "./ConsoleUI/Menu"
#define CONTROLS_URL "./ConsoleUI/Controls"
#define INSTRUCTIONS_URL "./ConsoleUI/Instructions"
#define INTRO_URL "./ConsoleUI/Intro"
#define ROOM_CONTROLS_URL "./ConsoleUI/RoomControls"

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
  // Sobrecarga de operadores para agragar o quitar item en el inventario del jugador.
  *player->getInventory() += new Item("Llave Final", "Esta llave te ayuda a abrir la puerta final", KEY, 1);
  
  try{
      vector<Item*> items = {
    new Item("Llave_Final", "Esta llave te ayuda a abrir la puerta final", KEY, 1),
    new Item("Espada", "Esta espada parece oxidada, pero servira de algo", WEAPON, 2),
    new Item("Palo_de_Madera", "Un simple palo de madera...", USELESS, 2)
    };

  Room* rooms[4] = {
    new Room("Cuarto 1301", "./Levels/Dialogs/Room1_D", items, 7, 14, false),
    new Room("Cuarto 1302", "./Levels/Dialogs/Room2_D", items, 7, 10, false),
    new Room("Cuarto 1303", "./Levels/Dialogs/Room3_D", items, 7, 6, true),
    new Room("Cuarto 1304", "./Levels/Dialogs/Room4_D", items, 7, 2, false)
    };

    map->setRooms(rooms);
    for(Room* room : map->getRooms()){
      cout << room->getName() << endl;
    }
    player->setMap(map);
  }catch(string e){
    cout << "Error al cargar valores iniciales en el juego: " << e << endl;
  }catch(overflow_error e){
    cout << "Overflow en valores iniciales: " << e.what() << endl;
  }

  try{
    printTextFile(MENU_URL, 2, false, true); // Print Menu
    int option;
    cin >> option;

    // Opciones del menu
    switch(option){
        case 1: // Play game
            setGameState(IN_GAME);
            gameLoop();
        break;
        case 2: // Introduccion
            printTextFile(INSTRUCTIONS_URL, 2, true, true);
            start();
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
    printTextFile(INTRO_URL, 2, true, true); // imprime la introduccion del juego

    while (this->gameState == IN_GAME){ // Mientras el juego este en el estado "IN_GAME" se ejecuta...
      display();  // Despliega texto a la consola
      getInput(); // Recibe input del usuario
      logic(); //
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
      playerContext = this->player->moveTo(RIGHT);
    break;
    case 'a':
      playerContext = this->player->moveTo(LEFT);
    break;
    case 'w':
      playerContext = this->player->moveTo(UP);
    break;
    case 's':
      playerContext = this->player->moveTo(DOWN);
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
  char auxInput;
  string auxInput2;
    switch(playerContext){
      case IN_ROOM:{
        do{
        Room* currentRoom = map->playerRoom();
        currentRoom->printInfo();
        printTextFile(ROOM_CONTROLS_URL, 1, false, false);
        cin >> auxInput;
        switch (tolower(auxInput)){
            case 'r':
                cout << "\n\nQue item quieres recoger: ";
                cin >> auxInput2;
                if (currentRoom->itemExists(auxInput2)){
                  Item* itemSelected = currentRoom->getItem(auxInput2);
                  currentRoom->deleteItem(itemSelected);
                  *player->getInventory() += itemSelected;
                  enterToContinue();
                }
            break;
            case 's':
                currentRoom->setPlayerIsIn(false);
            break;
          }
        }while(auxInput != 's');
        playerContext = NAVIGATE;
      break;
      }
      case COMBAT:

      break;
      case NAVIGATE:

      break;
    }
}

void Game::display(){
    clearScreen(0);
    this->map->print();
    printTextFile(CONTROLS_URL, 0, false, false);
}

void Game::clearScreen(float delay){
    addDelay(delay);
    if (system("CLS")) system("clear");
}

void Game::addDelay(float d){
  usleep(d * 100000);
}

void Game::enterToContinue(){
  cout << "\nPresiona ENTER para continuar...";
  cin.ignore(); cin.ignore();
}

void Game::printTextFile(string url, float delay, bool enterToContinue_, bool clearScreen_){
  try{
    if (clearScreen_){ // Limpia la pantalla
      clearScreen(0);
    }
    ifstream file(url);
    if (file.is_open()){
        string line;
        while(getline(file,line)){
            cout << line << endl;
            addDelay(delay); // Delay between text line
        }
        file.close();
    }
    if (enterToContinue_){ // Pausa hasta que el jugador ingresa un enter
      enterToContinue();
    }
  }catch(string e){
      cout << "Error al imprimir archivo de texto: " + e;
  }
}
