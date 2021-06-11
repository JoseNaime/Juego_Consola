// Un proyecto elaborado por: 
// Andrés Alejandro Guzmán González - A01633819
// José Pablo Naime García - A01367610
// © 2021 José Pablo Naime García Andrés Alejandro Guzmán González All Rights Reserved

#define MENU_URL "./ConsoleUI/Menu"
#define CONTROLS_URL "./ConsoleUI/Controls"
#define INSTRUCTIONS_URL "./ConsoleUI/Instructions"
#define INTRO_URL "./ConsoleUI/Intro"
#define ROOM_CONTROLS_URL "./ConsoleUI/RoomControls"
#define ESCAPED_URL "./ConsoleUI/FinalOk"
#define DIED_URL "./ConsoleUI/FinalNoOk"

#include <fstream>
#include <iostream>
#include <unistd.h>
#include <cctype>
#include <exception>
#include <map>

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
    std::map<string, Item*> items{
      {
        "Llave_Final",  new Item("Llave_Final", "Esta llave te ayuda a abrir la puerta final", KEY, 1)
      },
      {
        "Biblia",  new Item("Biblia", "Podria servir de algo", WEAPON, 2)
      },
      {
        "Llave_1303", new Item("Llave_1303", "Esta llave te ayuda a abrir el cuarto 1303", KEY, 1)
      },
      {
        "Pato_de_hule", new Item("Pato_de_hule", "CUAK CUAK CUAK", USELESS, 1)
      },
      {
        "Crucifijo", new Item("Crucifijo", "Poderoso para convatir demonios", WEAPON, 2)
      },
      {
        "Pistola_Oxidada", new Item("Pistola_Oxidada", "Parece un arma bastante vieja, ¿servira?", USELESS, 2)
      },
      {
        "Zapatos", new Item("Zapatos", "La moda en 1928", USELESS, 2)
      },
      {
        "Agua_Bendita", new Item("Agua_Bendita", "Parece muy bendita", WEAPON, 1) 
      },
      {
        "Veladora", new Item("Veladora", "¿Necesitas alumbrar tu camino?", USELESS, 1) 
      },
      {
        "Reloj", new Item("Reloj", "Tik-tak, tik-tak, tik tak", USELESS, 1)
      },
    }; // Instancias de Items

    Room* rooms[4] = {
    new Room(1301, "Cuarto 1301", "./Levels/Dialogs/Room1_D", {items["Veladora"], items["Reloj"], items["Zapatos"]}, nullptr, 7, 14, false),
    new Room(1302, "Cuarto 1302", "./Levels/Dialogs/Room2_D", {items["Pato_de_hule"], items["Pistola_Oxidada"], items["Agua_Bendita"]}, nullptr, 7, 10, false),
    new Room(1303, "Cuarto 1303", "./Levels/Dialogs/Room3_D", new Enemy("Alloc", 3, 2, "Parece enojado...", items["Llave_Final"] ), 7, 6, true),
    new Room(1304, "Cuarto 1304", "./Levels/Dialogs/Room4_D", {items["Crucifijo"], items["Llave_1303"]}, nullptr, 7, 2, false),
    }; // Instancias de Cuartos

    map->setRooms(rooms);
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
      logic(); // Ejecuta la logica del juego
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
      this->player->getInventory()->printInventory(true);
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
            case 'r':{
              bool itemExists = false;
              do{
                  cout << "\n\nQue item quieres recoger: ";
                  cin >> auxInput2;
                  itemExists = currentRoom->itemExists(auxInput2);
                  if (itemExists){
                    Item* itemSelected = currentRoom->getItem(auxInput2);
                    currentRoom->deleteItem(itemSelected);
                    *player->getInventory() += itemSelected;
                    enterToContinue();
                  }else{
                    cout << "Ese item no existe" << endl;
                  }
              }while(!itemExists);
            break;
            }
            case 'd':
                currentRoom->setPlayerIsIn(false); // El jugador sale del cuarto
            break;
          }
        }while(auxInput != 'd');
        playerContext = NAVIGATE;
      break;
      }
      case COMBAT:{
        Room* currentRoom = map->playerRoom();
        Enemy* enemy = currentRoom->getEnemy();
        currentRoom->printInfo();
        cout << "\nPara combatir a " << enemy->getName() << " necesitas utilizar algun item de tu inventario..." << endl;
        if (player->getInventory()->getCurrentSpace() == 0){
          cout << "Tu inventario esta vacio...\n" <<"No tienes como combatir a " << enemy->getName() << " y tampoco tienes escapatoria, por lo que " << enemy->getName() << " te ataca y te mata, es tu FIN...";
          playerContext = DIED;
          enterToContinue();
          logic();
        }else{
          player->getInventory()->printInventory(false);
          bool itemExists = false;
          
          do{
            clearScreen(0);
            currentRoom->printInfo(0);
            cout << "\nPara combatir a " << enemy->getName() << " necesitas utilizar algun item de tu inventario..." << endl;
            player->getInventory()->printInventory(false);
            cout << "\n\nQue item quieres utilizar: ";
            cin >> auxInput2;
            itemExists = player->getInventory()->itemExists(auxInput2);
            if (itemExists){
              Item* itemSelected = player->getInventory()->getItem(auxInput2);
              if (itemSelected->getItemType() == WEAPON){ // Si el item es una ARMA
                player->attack(enemy);
                if (enemy->getLives() <= 0){
                  playerContext = ESCAPED;
                  cout << "\nLograste vencer a " << enemy->getName() << " !!" << endl;
                  cout << "El enemigo solto un item, por lo que decides tomarlo..." << endl;
                  *player->getInventory() += enemy->getEnemyItem();
                  enterToContinue();
                  logic();
                  break;
                }else{
                cout << "Has dañado a " << enemy->getName() << " !!\n" << "Pero parece resisir..." << endl;
                }
              }else{ // Si el item NO es un ARMA
                enemy->attack(player);
                if (player->getLives() <= 0){
                  playerContext = DIED;
                  logic();
                  break;
                }
              }
              *player->getInventory() -= itemSelected;
              enterToContinue();
            }else{
              cout << "Ese item no existe" << endl;
            }
          }while(!itemExists || player->getLives() > 0);
        }
        enterToContinue();
      break;
      }
      case NAVIGATE:
      break;
      case ESCAPED:
        printTextFile(ESCAPED_URL, 1.5, false, true);
        gameState = START;
        start();
      break;
      case DIED:
        printTextFile(DIED_URL, 1.5, false, true);
        gameState = START;
        start();
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
