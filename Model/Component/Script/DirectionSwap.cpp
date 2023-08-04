#include "DirectionSwap.hpp"

using namespace components;

DirectionSwap::DirectionSwap(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fTicks = 0.0f;
    this->fSwitchInterval = BLOCKER_LENGTH + (float)(std::rand()%(BLOCKER_VARIATION * 100)/100.f);
    this->bDirection = std::rand()%2;
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



