#ifndef PROYECTO_JUEGO_CHARACTER_H
#define PROYECTO_JUEGO_CHARACTER_H

#include "string"
using namespace std;

class Character{
public:
  Character();
  Character(string, int, int);

  string getName() const;
  int getLives() const;
  int getDamage() const;

  void setName(string);
  void setLives(int);
  void setDamage(int);

  void attack(int, Character*);
private:
  string name;
  int lives, damage;
};

#endif