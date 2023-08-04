#include "BlockerManager.hpp"

using namespace controllers;

void BlockerManager::addBlocker(PoolableObject* pBlocker){
    this->vecBlocker.push_back(pBlocker);
}

void BlockerManager::clearAll(){
    this->vecBlocker.clear();
}

std::vector<PoolableObject*> BlockerManager::getBlockers(){
    return this->vecBlocker;
}

BlockerManager* BlockerManager::P_SHARED_INSTANCE = NULL;
BlockerManager::BlockerManager() {}
BlockerManager::BlockerManager(const BlockerManager&) {}

BlockerManager* BlockerManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new BlockerManager();

    return P_SHARED_INSTANCE;
}