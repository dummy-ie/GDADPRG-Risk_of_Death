#include "Mover.hpp"

using namespace components;

Mover::Mover(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fSpeedMultiplier = 1.0f;
    this->fUpdateTicks = 0.0f;
    this->fUpdateTicks2 = 0.0f;
}

void Mover::perform() {
    float fFrameInterval = 0.01f;

    this->fUpdateTicks2 += this->tDeltaTime.asSeconds();
    this->fUpdateTicks += this->tDeltaTime.asSeconds();
    if (this->fUpdateTicks >= fFrameInterval) {
        this->fUpdateTicks = 0.0f;
        if(!PowerUpSystem::getInstance()->isActive(ItemType::PWR_FREEZE)){
            this->move();
        }
    }
    if (this->fUpdateTicks2 >= 10.0f) {
        this->fUpdateTicks2 = 0.0f;
        this->fSpeedMultiplier += 0.01;
    }
}

void Mover::move() {
    if(this->pMovable == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        this->pMovable->move(this->fSpeedMultiplier, this->tDeltaTime);
    }
}

void Mover::setMovable(Movable* pMovable) {
    this->pMovable = pMovable;

}