//
// Created by Jose Naime on 14/05/21.
//

#include "Player.h"

Player::Player() {
    this->posX = 1;
    this->posY = 1;
}

Player::Player(int x, int y){
    this->posX = x;
    this->posY = y;
}

void Player::moveTo(DIRECTION dir){
    int move [2] = {0,0};
    switch (dir){
        case RIGHT:
            move[0] = 1;
            break;
        case LEFT:
            move[0] = -1;
            break;
        case UP:
            move[1] = 1;
            break;
        case DOWN:
            move[1] = -1;
            break;
        default:
            std::cout << "Direccion Invalida" << std::endl;

    }
    if (move[0] != 0 || move[1] != 0){

        setPos(getPosX() + move[0], getPosY() + move[1]);
    }

}

int Player::getPosX() const{
    return posX;
}

int Player::getPosY() const{
    return posY;
}

void Player::setPos(int x, int y){
    this->posX = x;
    this->posY = y;
}

void Player::setPosX(int x){
    this->posX = x;
}

void Player::setPosY(int y){
    this->posY = y;
}

