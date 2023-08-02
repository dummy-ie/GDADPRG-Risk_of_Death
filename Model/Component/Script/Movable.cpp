#include "Movable.hpp"

using namespace components;

Movable::Movable(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    float fTicks = 0.0f;
}

void Movable::perform() {
    float fFrameInterval = 0.01f;
    Enemy* pEnemy = (Enemy*)this->pOwner;
    if(pEnemy == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        this->fTicks += this->tDeltaTime.asSeconds() * GAME_SPEED;

        if (this->fTicks > fFrameInterval) {
            this->fTicks = 0.0f;
            float fMovement = pEnemy->getSpeed() * this->tDeltaTime.asSeconds();
            //float fMovement = 0.00001f;
            //std::cout << fMovement << std::endl;
            float fSize = pEnemy->getSize();
            pEnemy->setDistance(pEnemy->getDistance() + fMovement);
            float fDistance = pEnemy->getDistance() / SCREEN_WIDTH;
            pEnemy->getSprite()->setScale(fSize + fDistance, fSize + fDistance);
        }
    }
}