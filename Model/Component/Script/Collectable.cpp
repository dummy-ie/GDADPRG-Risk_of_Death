#include "Collectable.hpp"

using namespace components;

Collectable::Collectable(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fTimer = -1.f;
    this->fFrameInterval = 1.f;
    this->fTicks = 0.f;

    this->bCollected = false;
}

void Collectable::perform() {
    if(this->bCollected) {
        PoolableObject* pPoolableObject = (PoolableObject*)this->getOwner();
        ObjectPoolManager::getInstance()->getPool(pPoolableObject->getTag())->releasePoolable(pPoolableObject);
        this->bCollected = false;
        this->fTimer = -1.f;
    }

    this->fTicks += this->tDeltaTime.asSeconds() * GAME_SPEED;
    if(this->fTicks > this->fFrameInterval){
        if(this->fTimer == 0.f){
            this->bCollected = true;
        }
        else if(this->fTimer > 0.f){
            this->fTimer -= 1.f;
        }
        else{
            this->fTimer = 0.f;
        }
        this->fTicks = 0.f;
    }
}

void Collectable::startTimer(){
    this->fTimer = 10.f;
}

bool Collectable::isCollected() {
    return this->bCollected;
}

void Collectable::setCollected(bool bCollected) {
    this->bCollected = bCollected;
}
