#include "EnemyManager.hpp"

using namespace controllers;

EnemyManager* EnemyManager::P_SHARED_INSTANCE = NULL;
EnemyManager::EnemyManager() {}
EnemyManager::EnemyManager(const EnemyManager&) {}

EnemyManager* EnemyManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new EnemyManager();

    return P_SHARED_INSTANCE;
}