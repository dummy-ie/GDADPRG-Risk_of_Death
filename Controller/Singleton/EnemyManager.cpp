#include "EnemyManager.hpp"

using namespace controllers;

void EnemyManager::create(EnemyType EType, std::string strName) {
    
}

void EnemyManager::addEnemy(Enemy* pEnemy) {
    this->vecEnemies.push_back(pEnemy);
}

std::vector<Enemy*> EnemyManager::getEnemies() {
    return this->vecEnemies;
}

EnemyManager* EnemyManager::P_SHARED_INSTANCE = NULL;
EnemyManager::EnemyManager() {}
EnemyManager::EnemyManager(const EnemyManager&) {}

EnemyManager* EnemyManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new EnemyManager();

    return P_SHARED_INSTANCE;
}