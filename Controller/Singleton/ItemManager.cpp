#include "ItemManager.hpp"

using namespace controllers;

void ItemManager::addItem(ItemType EType, bool bActive){
    if(bActive){
        this->vecActiveItems.push_back(EType);
    }
    else if(this->nItems < 3){
        bool nEnd = false;
        for(int i = 0; i < 3 && !nEnd; i++){
            if(this->mapItems[i] == ItemType::NONE){
                this->mapItems[i] = EType;
                nEnd = true;
                std::cout << "[INFO] : Added "<< (int)EType << " to " << i << std::endl;
            }
        }
        this->nItems++;
        std::cout << "[INFO] : Slots be at " << this->nItems << std::endl;
    }
    else{
        std::cout << "[WARNING] : No slots." << std::endl;
    }
}

bool ItemManager::useItem(int nIndex){
    if(this->mapItems[nIndex] != ItemType::NONE){
        this->mapItems[nIndex] = ItemType::NONE;
        this->nItems--;
        std::cout << "[INFO] : Slots be at " << this->nItems << std::endl;
        std::cout << (int)this->mapItems[0] << " " << (int)this->mapItems[1] << " " << (int)this->mapItems[2] << std::endl;
        return true;
    }
    this->nItems--;
    std::cout << (int)this->mapItems[0] << " " << (int)this->mapItems[1] << " " << (int)this->mapItems[2] << std::endl;
    return false;
}

std::vector<ItemType> ItemManager::getActiveItems(){
    std::vector<ItemType> vecActiveItems = this->vecActiveItems;
    this->vecActiveItems.clear();
    return vecActiveItems;
}

ItemType ItemManager::getItem(int nIndex){
    return this->mapItems[nIndex];
}

void ItemManager::deleteAllItems(){
    this->mapItems.clear();
}

ItemManager* ItemManager::P_SHARED_INSTANCE = NULL;
ItemManager::ItemManager() {
    this->nItems = 0;
    this->mapItems[0] = ItemType::NONE;
    this->mapItems[1] = ItemType::NONE;
    this->mapItems[2] = ItemType::NONE;
}
ItemManager::ItemManager(const ItemManager&) {
    this->nItems = 0;
    this->mapItems[0] = ItemType::NONE;
    this->mapItems[1] = ItemType::NONE;
    this->mapItems[2] = ItemType::NONE;
}

ItemManager* ItemManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new ItemManager();

    return P_SHARED_INSTANCE;
}