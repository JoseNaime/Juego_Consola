// Un proyecto elaborado por: 
// Andrés Alejandro Guzmán González - A01633819
// José Pablo Naime García - A01367610
// © 2021 José Pablo Naime García Andrés Alejandro Guzmán González All Rights Reserved

#ifndef PROYECTO_JUEGO_CHARACTER_H
#define PROYECTO_JUEGO_CHARACTER_H

// Character es la clase padre de las clases Player y Enemy

#include "string"
using namespace std;

class Character{
    public:
      Character(); // Constructor sin parametros
      Character(string, int, int); // Constructor con parametros

      string getName() const; // Regresa el nombre del personaje
      int getLives() const; // Regresa las vidas del personaje
      int getDamage() const; // Regresa los puntos de daño del personaje

      void setName(string); // Asigna el nombre del personaje
      void setLives(int); // Asigna las vidas del personaje
      void setDamage(int); // Asigna el nivel de daño

      //Declarada como VIRTUAL en UML
      virtual void attack(Character*) = 0; // Funcion de ataque
    private:
      string name;
      int lives, damage;
};

#endif