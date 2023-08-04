#include "DirectionSwap.hpp"

using namespace components;

DirectionSwap::DirectionSwap(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fTicks = 0.0f;
    this->fSwitchInterval = 5.f;
    this->bDirection = false;
}

void DirectionSwap::perform() {
    this->fTicks += this->tDeltaTime.asSeconds() * GAME_SPEED;
    if(this->fTicks > this->fSwitchInterval){
        this->bDirection = !this->bDirection;
        this->fTicks = 0.f;
    }
}

bool DirectionSwap::getDirection(){
    return this->bDirection;
}



