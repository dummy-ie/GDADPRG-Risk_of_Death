#include "ItemManager.hpp"

using namespace controllers;

ItemManager* ItemManager::P_SHARED_INSTANCE = NULL;
ItemManager::ItemManager() {}
ItemManager::ItemManager(const ItemManager&) {}

ItemManager* ItemManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new ItemManager();

    return P_SHARED_INSTANCE;
}