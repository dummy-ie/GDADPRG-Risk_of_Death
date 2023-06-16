#include "BlockerManager.hpp"

using namespace controllers;

BlockerManager* BlockerManager::P_SHARED_INSTANCE = NULL;
BlockerManager::BlockerManager() {}
BlockerManager::BlockerManager(const BlockerManager&) {}

BlockerManager* BlockerManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new BlockerManager();

    return P_SHARED_INSTANCE;
}