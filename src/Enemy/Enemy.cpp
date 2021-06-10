// Un proyecto elaborado por: 
// Andrés Alejandro Guzmán González - A01633819
// José Pablo Naime García - A01367610
// © 2021 José Pablo Naime García Andrés Alejandro Guzmán González All Rights Reserved

#include "Enemy.h"

Enemy::Enemy(){

}

Enemy::Enemy(string n, int liv, int dam, string desc, Item* it):Character(n, liv, dam){
    enemyDescriptUrl = desc;
    item = it;
}

string Enemy::getEnemyDescriptUrl() const{
    return enemyDescriptUrl;
}

void Enemy::setEnemyDescriptUrl(string desc){
    enemyDescriptUrl = desc;
}

Item* Enemy::getEnemyItem(){
    return item;
}

void Enemy::setEnemy(Item* it){
    item = it;
}