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