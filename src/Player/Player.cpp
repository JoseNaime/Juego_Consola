#include "Player.h"

Player::Player() {
    posX = 1;
    posY = 1;
}

Player::Player(string n, int liv, int dam, int x, int y):Character(n, liv, dam){
    posX = x;
    posY = y;
}

void Player::moveTo(DIRECTION dir, Map& map){
    int move [2] = {0,0};
    switch (dir){
        case RIGHT:
            move[0] = 1;
            break;
        case LEFT:
            move[0] = -1;
            break;
        case UP:
            move[1] = -1;
            break;
        case DOWN:
            move[1] = 1;
            break;
        default:
            cout << "Direccion Invalida" << endl;
    }
    if (move[0] != 0 || move[1] != 0){

        if (map.getPosition(getPosX() + move[0], getPosY() + move[1]) == '.'){ // Checa si es un movimiento valido
          char currPosChar = map.getPosition(getPosX(), getPosY()); // Salva el caracter 
          setPos(getPosX() + move[0], getPosY() + move[1]);
          map.setPosition(getPosX() - move[0], getPosY() - move[1], '.');
          map.setPosition(getPosX(), getPosY(), 'P');
        }
        
    }


}

int Player::getPosX() const{
    return posX;
}

int Player::getPosY() const{
    return posY;
}

void Player::setPos(int x, int y){
    posX = x;
    posY = y;
}

void Player::setPosX(int x){
    posX = x;
}

void Player::setPosY(int y){
    posY = y;
}

