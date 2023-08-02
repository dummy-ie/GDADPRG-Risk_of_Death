#include "Mover.hpp"

using namespace components;

Mover::Mover(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fTicks = 0.0f;
}

void Mover::perform() {
    float fFrameInterval = 0.01f;

    this->fTicks += this->tDeltaTime.asSeconds();
    if (this->fTicks >= fFrameInterval) {
        this->fTicks = 0.0f;
        this->move();
    }
}

void Mover::move() {
    if(this->pMovable == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        this->pMovable->move(this->tDeltaTime);
    }
}

void Mover::setMovable(Movable* pMovable) {
    this->pMovable = pMovable;

}