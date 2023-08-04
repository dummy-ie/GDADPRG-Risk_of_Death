#include "BlockerManager.hpp"

using namespace controllers;

void BlockerManager::addBlocker(PoolableObject* pBlocker){
    this->vecBlocker.push_back(pBlocker);
}

void BlockerManager::deleteBlocker(PoolableObject* pBlocker){
    std::string strName = pBlocker->getName();
    int nIndex = -1;

    for (int i = 0; i < this->vecBlocker.size() && nIndex == -1; i++)
    {
        if (this->vecBlocker[i] == pBlocker)
            nIndex = i;
    }

    if (nIndex != -1)
    {
        this->vecBlocker.erase(this->vecBlocker.begin() + nIndex);
        delete pBlocker;
    }
}

void BlockerManager::deleteAllBlockers(){
    for (PoolableObject *pBlocker : this->vecBlocker)
    {
        this->deleteBlocker(pBlocker);
    }

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