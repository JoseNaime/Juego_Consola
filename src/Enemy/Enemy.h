#ifndef PROYECTO_JUEGO_ENEMY_H
#define PROYECTO_JUEGO_ENEMY_H

#include "../Character/Character.h"
#include "../Item/Item.h"

class Enemy: public Character{
    public:
        Enemy();
        Enemy(string, int, int, string, Item*);
        string getEnemyDescriptUrl() const;
        void setEnemyDescriptUrl(string);
        Item* getEnemyItem();
        void setEnemy(Item*);
    private:
        string enemyDescriptUrl;
        Item* item;
};

#endif // PROYECTO_JUEGO_ENEMY_H