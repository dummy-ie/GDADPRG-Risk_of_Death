#include "ItemManager.hpp"

using namespace controllers;

void ItemManager::addItem(ItemType EType){
    this->mapItems[EType] += 1;
}

bool ItemManager::useItem(ItemType EType){
    if(this->mapItems.count(EType) > 0 && this->mapItems[EType] > 0){
        this->mapItems[EType] -= 1;
        return true;
    }
    return false;
}

int ItemManager::getItemCount(ItemType EType){
    return this->mapItems.count(EType);
}

void ItemManager::deleteAllItems(){
    this->mapItems.clear();
}

ItemManager* ItemManager::P_SHARED_INSTANCE = NULL;
ItemManager::ItemManager() {}
ItemManager::ItemManager(const ItemManager&) {}

ItemManager* ItemManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new ItemManager();

    return P_SHARED_INSTANCE;
}