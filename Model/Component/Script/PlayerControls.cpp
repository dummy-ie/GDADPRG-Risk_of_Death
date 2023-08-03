#include "PlayerControls.hpp"

using namespace components;

PlayerControls::PlayerControls(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fCooldown = 0.5f;
    this->vecTimer = {0.f,0.f,0.f};
}

void PlayerControls::perform() {
    this->fTicks += this->tDeltaTime.asSeconds() * GAME_SPEED;

    if(this->fTicks > 0.5f){
        this->fTicks = 0.f;
        for(float& fTimer : this->vecTimer){
            if(fTimer > 0.f){
                fTimer -= 0.5f;
                if(fTimer < 0.f){
                    fTimer = 0.f;
                }
            }
        }
    }

    PlayerInput* pInput = (PlayerInput*)this->getOwner()->findComponentByName(this->pOwner->getName() + " Input");
    
    if(pInput == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        if(pInput->isLeft()) {
            GameObjectManager::getInstance()->findObjectByName("Background")->setFrame(1);
        }

        if(pInput->isRight()) {
            GameObjectManager::getInstance()->findObjectByName("Background")->setFrame(0);
        }

        if(pInput->is1() && this->vecTimer[0] == 0.f){
            if(ItemManager::getInstance()->useItem(ItemType::PWR_DAMAGE)){
                std::cout << "[ITEM] : Damage item used, " << ItemManager::getInstance()->getItemCount(ItemType::PWR_DAMAGE) << " left." << std::endl;
                PowerUpSystem::getInstance()->activatePowerUp(ItemType::PWR_DAMAGE);
                this->vecTimer[0] = this->fCooldown * 2.f;
            }
            else{
                std::cout << "[ERROR] : No damage items left." << std::endl;
                this->vecTimer[0] = this->fCooldown;
            }
        }

        if(pInput->is2() && this->vecTimer[1] == 0.f){
            if(ItemManager::getInstance()->useItem(ItemType::PWR_PIERCE)){
                std::cout << "[ITEM] : Pierce item used, " << ItemManager::getInstance()->getItemCount(ItemType::PWR_PIERCE) << " left." << std::endl;
                PowerUpSystem::getInstance()->activatePowerUp(ItemType::PWR_PIERCE);
                this->vecTimer[1] = this->fCooldown * 2.f;
            }
            else{
                std::cout << "[ERROR] : No pierce items left." << std::endl;
                this->vecTimer[1] = this->fCooldown;
            }
        }

        if(pInput->is3() && this->vecTimer[2] == 0.f){
            if(ItemManager::getInstance()->useItem(ItemType::PWR_FREEZE)){
                std::cout << "[ITEM] : Freeze item used, " << ItemManager::getInstance()->getItemCount(ItemType::PWR_FREEZE) << " left." << std::endl;
                PowerUpSystem::getInstance()->activatePowerUp(ItemType::PWR_FREEZE);
                this->vecTimer[2] = this->fCooldown * 2.f;
            }
            else{
                std::cout << "[ERROR] : No freeze items left." << std::endl;
                this->vecTimer[2] = this->fCooldown;
            }
        }

        if (pInput->isR()) {
            Player* pPlayer = (Player*)this->getOwner();

            if (pPlayer)
            {
                std::cout << "calling player start" << std::endl;
                pPlayer->start();
            }
        }

        if(pInput->isZoomOut())
        {
            // Player* pPlayer = (Player*)this->getOwner();
            Player* pPlayer = (Player*)GameObjectManager::getInstance()->findObjectByName("Player");

            if (pPlayer && WindowManager::getInstance()->getPartitions()->size() > 1)
            {

                pPlayer->setZoomedIn(false);
            }
        }

    }
    
}
