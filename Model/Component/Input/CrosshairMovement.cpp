#include "CrosshairMovement.hpp"

using namespace components;

CrosshairMovement::CrosshairMovement(std::string strName) : Component(strName, ComponentType::SCRIPT) {}

void CrosshairMovement::perform() {
    CrosshairMouseInput* pCrosshairMouseInput = (CrosshairMouseInput*)this->getOwner()->getComponents(ComponentType::INPUT)[0];
    sf::Sprite* pSprite = this->getOwner()->getSprite();

    if(pCrosshairMouseInput == NULL || pSprite == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        this->pOwner->getSprite()->setPosition(pCrosshairMouseInput->getLocation().x, pCrosshairMouseInput->getLocation().y);
    }   
}
