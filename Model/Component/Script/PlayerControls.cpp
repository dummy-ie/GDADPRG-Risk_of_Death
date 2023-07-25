#include "PlayerControls.hpp"

using namespace components;

PlayerControls::PlayerControls(std::string strName) : Component(strName, ComponentType::SCRIPT) {}

void PlayerControls::perform() {
    PlayerInput* pInput = (PlayerInput*)this->getOwner()->findComponentByName(this->pOwner->getName() + " Input");
    
    if(pInput == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        if(pInput->isLeft()) {
            GameObjectManager::getInstance()->findObjectByName("Game Background Side")->setEnabled(true);
            GameObjectManager::getInstance()->findObjectByName("Game Background Front")->setEnabled(false);
        }

        if(pInput->isRight()) {
            GameObjectManager::getInstance()->findObjectByName("Game Background Side")->setEnabled(false);
            GameObjectManager::getInstance()->findObjectByName("Game Background Front")->setEnabled(true);
        }

    }
}