/* * * * * * * * * * * * * * * * * * * * * 
 *     Make this a killer system! :)     * 
 * * * * * * * * * * * * * * * * * * * * */

#include "ItemCollectorSystem.hpp"

using namespace systems;

void ItemCollectorSystem::collect(sf::Vector2f vecLocation) {
    int nCollect = -1;
    float fCollectThreshold = 40.f;

    for (int i = this->vecCollectable.size() - 1; i >= 0; i--) {
        Item* pItem = (Item*) this->vecCollectable[i]->getOwner();
        if (pItem->contains(vecLocation)) {
            if (this->vecCollectable[i]->getOwner()->isEnabled()) {

                //if this becomes false, then wtf
                if(pItem){
                    pItem->collect();
                }
                this->vecCollectable[i]->setCollected(true);
                //nCollect = 1;
            }
        }
    }
}

void ItemCollectorSystem::perform() {}

void ItemCollectorSystem::registerComponent(Collectable* pCollectable) {
    this->vecCollectable.push_back(pCollectable);
}

void ItemCollectorSystem::unregisterComponent(Collectable* pCollectable) {
    int nIndex = -1;

    for(int i = 0; i < this->vecCollectable.size() && nIndex == -1; i++) {
        if(this->vecCollectable[i] == pCollectable)
            nIndex = i;
    }

    if(nIndex != -1) {
        this->vecCollectable.erase(this->vecCollectable.begin() + nIndex);
    }
}

void ItemCollectorSystem::clearAll(){
    this->vecCollectable.clear();
}

/* * * * * * * * * * * * * * * * * * * * * 
 *       SINGLETON-RELATED CONTENT       * 
 * * * * * * * * * * * * * * * * * * * * */

ItemCollectorSystem* ItemCollectorSystem::P_SHARED_INSTANCE = NULL;
ItemCollectorSystem::ItemCollectorSystem(std::string strName) : Component(strName, ComponentType::SCRIPT) {}
ItemCollectorSystem::ItemCollectorSystem(const ItemCollectorSystem& CObject) : Component(CObject.strName, ComponentType::SCRIPT) {}

ItemCollectorSystem* ItemCollectorSystem::getInstance() {
    return P_SHARED_INSTANCE;
}

void ItemCollectorSystem::initialize(std::string strName, GameObject* pParent) {
    P_SHARED_INSTANCE = new ItemCollectorSystem(strName);
    pParent->attachComponent(P_SHARED_INSTANCE);
}
