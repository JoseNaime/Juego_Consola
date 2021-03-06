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
    // Instancias de Items
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
    }; 

    // Instancias de Cuartos
    Room* rooms[4] = {
    new Room(1301, "Cuarto 1301", "./Levels/Dialogs/Room1_D", {items["Veladora"], items["Reloj"], items["Zapatos"]}, nullptr, 7, 14, false),
    new Room(1302, "Cuarto 1302", "./Levels/Dialogs/Room2_D", {items["Pato_de_hule"], items["Pistola_Oxidada"], items["Agua_Bendita"]}, nullptr, 7, 10, false),
    new Room(1303, "Cuarto 1303", "./Levels/Dialogs/Room3_D", new Enemy("Alloc", 3, 2, "Parece enojado...", items["Llave_Final"] ), 7, 6, true),
    new Room(1304, "Cuarto 1304", "./Levels/Dialogs/Room4_D", {items["Crucifijo"], items["Llave_1303"]}, nullptr, 7, 2, false),
    }; 

    map->setRooms(rooms); // Agregamos los cuartos a nuestro mapa
    player->setMap(map);  // Agregamos el mapa a nuestro jugador
  }catch(string e){
    cout << "Error al cargar valores iniciales en el juego: " << e << endl;
  }catch(overflow_error e){
    cout << "Overflow en valores iniciales: " << e.what() << endl;
  }

  /// ------------ MENU del juego -----------------
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
      logic();    // Ejecuta la logica del juego
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

    default:
      cout << "Valor invalido\nIngresa un nuevo valor: ";
      getInput();
    break;
  }
}

void Game::logic(){ // Logica del juego
  char auxInput;
  string auxInput2;
    // Switch dependiendo el contexto de nuestro jugador
    switch(playerContext){
      /// El jugador se encuentra dentro de un cuart\o
      case IN_ROOM:{    
        do{
        Room* currentRoom = map->playerRoom();              // Regresa el cuarto en el que esta el jugador
        currentRoom->printInfo();                           // Imprime la informacion del mapa
        printTextFile(ROOM_CONTROLS_URL, 1, false, false);  // Imprime los controles del cuarto
        cin >> auxInput;
        switch (tolower(auxInput)){
            // Recoger un item
            case 'r':{
              bool itemExists = false;
              do{
                  cout << "\n\nQue item quieres recoger: ";
                  cin >> auxInput2;
                  itemExists = currentRoom->itemExists(auxInput2);
                  if (itemExists){  // Si el item existe
                    Item* itemSelected = currentRoom->getItem(auxInput2);
                    currentRoom->deleteItem(itemSelected);   // Borra item del cuarto
                    *player->getInventory() += itemSelected; // Agrega item a inventario
                    enterToContinue();
                  }else{
                    cout << "Ese item no existe" << endl;
                  }
              }while(!itemExists);
            break;
            }
            // Salir del cuarto
            case 'd':
                currentRoom->setPlayerIsIn(false); // El jugador sale del cuarto
            break;
          }
        }while(auxInput != 'd');
        playerContext = NAVIGATE;
      break;
      }
      /// El jugador se encuentra en combate
      case COMBAT:{
        Room* currentRoom = map->playerRoom();    // Regresa el cuarto en el que esta el jugador
        Enemy* enemy = currentRoom->getEnemy();   // Regresa el enemigo que se encuentra en el cuarto
        currentRoom->printInfo();                 // Imprime la informacion del cuarto
        cout << "\nPara combatir a " << enemy->getName() << " necesitas utilizar algun item de tu inventario..." << endl;
        bool itemExists = false;
        // Si el jugador no tiene ningun item en el inventario...
        do{
          if (player->getInventory()->getCurrentSpace() <= 0){ 
            cout << "\nTu inventario esta vacio...\n\n" <<"No tienes como combatir a " << enemy->getName() << " y tampoco tienes escapatoria, por lo que " << enemy->getName() << " te ataca y te mata, es tu FIN...";
            playerContext = DIED;     
            enterToContinue();
            logic();
          }else{
              clearScreen(0);
              currentRoom->printInfo(0);
              cout << "\nPara combatir a " << enemy->getName() << " necesitas utilizar algun item de tu inventario..." << endl;
              player->getInventory()->printInventory(false);
              cout << "\n\nQue item quieres utilizar: ";
              cin >> auxInput2;
              itemExists = player->getInventory()->itemExists(auxInput2);
              // Si el item elegido existe...
              if (itemExists){
                Item* itemSelected = player->getInventory()->getItem(auxInput2); // Regresa el item escogido
                if (itemSelected->getItemType() == WEAPON){ // Si el item es una ARMA
                  player->attack(enemy);                    // Ataca al enemigo
                  if (enemy->getLives() <= 0){              // Si la vida del enemigo es menor o igual a 0...
                    playerContext = ESCAPED;                
                    cout << "\nLograste vencer a " << enemy->getName() << " !!" << endl;
                    cout << "El enemigo solto un item, por lo que decides tomarlo..." << endl;
                    *player->getInventory() += enemy->getEnemyItem();     // Se agrega item del enemigo al jugador
                    enterToContinue();
                    logic();
                    break;
                  }else{
                  cout << "Has dañado a " << enemy->getName() << " !!\n" << "Pero parece resisir..." << endl;
                  }
                }else{ // Si el item NO es un ARMA
                  enemy->attack(player);          // El enemigo ataca al jugador
                  if (player->getLives() <= 0){   // Si las vidas del jugador son menores o iguales a 0...
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
          }
        }while(!itemExists || player->getLives() > 0);
        enterToContinue();
      break;
      }
      /// El jugador esta navegando por el mapa
      case NAVIGATE:
      break; 
      /// El jugador gano el juego
      case ESCAPED:
        printTextFile(ESCAPED_URL, 1.5, false, true);
        enterToContinue();
        gameState = START;
        start();
      break;
      /// El jugador perdio el juego
      case DIED:
        printTextFile(DIED_URL, 1.5, false, true);
        enterToContinue();
        gameState = START;
        start();
      break;
    }
}

void Game::display(){  // Limpia la pantalla e imprime el mapa
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
