// Un proyecto elaborado por: 
// Andrés Alejandro Guzmán González - A01633819
// José Pablo Naime García - A01367610
// © 2021 José Pablo Naime García Andrés Alejandro Guzmán González All Rights Reserved

#include "Character.h"

Character::Character() {
  name = "";
  lives = 1;
  damage = 1;
}

Character::Character(string nam, int liv, int dam){
  name = nam;
  lives = liv;
  damage = dam;
}

void Character::attack(int damage, Character *target){
  target->setLives(getLives() - damage);
}

string Character::getName() const{
  return name;
}

int Character::getLives() const{
  return lives;
}

int Character::getDamage() const{
  return damage;
}

void Character::setName(string n) {
  name = n;
}

void Character::setLives(int l){
  lives = l;
}

void Character::setDamage(int d){
  damage = d;
} 