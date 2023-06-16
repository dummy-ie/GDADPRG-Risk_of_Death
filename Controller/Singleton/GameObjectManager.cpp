#include "GameObjectManager.hpp"

using namespace controllers;

GameObjectManager* GameObjectManager::P_SHARED_INSTANCE = NULL;
GameObjectManager::GameObjectManager() {}
GameObjectManager::GameObjectManager(const GameObjectManager&) {}

GameObjectManager* GameObjectManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new GameObjectManager();

    return P_SHARED_INSTANCE;
}