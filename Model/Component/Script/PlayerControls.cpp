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

        if(pInput->is1()){
            ItemManager::getInstance()->useItem(ItemType::PWR_DAMAGE);
        }

        if(pInput->is2()){
            ItemManager::getInstance()->useItem(ItemType::PWR_PIERCE);
        }

        if(pInput->is3()){
            ItemManager::getInstance()->useItem(ItemType::PWR_FREEZE);
        }

        if(pInput->isPartition())
        {
            sf::View vwView(sf::Vector2f(SCREEN_WIDTH / 8, SCREEN_HEIGHT / 8), sf::Vector2f(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4));
            WindowManager::getInstance()->getWindow()->setView(vwView);
        }

        if(pInput->isZoomOut())
        {
            WindowManager::getInstance()->getWindow()->setView(WindowManager::getInstance()->getWindow()->getDefaultView());
        }

    }
}
