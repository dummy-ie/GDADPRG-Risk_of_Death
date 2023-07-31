#include "Collectable.hpp"

using namespace components;

Collectable::Collectable(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->bCollected = false;
}

void Collectable::perform() {
    if(this->bCollected) {
        PoolableObject* pPoolableObject = (PoolableObject*)this->getOwner();
        ObjectPoolManager::getInstance()->getPool(pPoolableObject->getTag())->releasePoolable(pPoolableObject);
        this->bCollected = false;
    }
}

bool Collectable::isCollected() {
    return this->bCollected;
}

void Collectable::setCollected(bool bCollected) {
    this->bCollected = bCollected;
}
