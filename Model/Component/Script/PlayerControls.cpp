#include "PlayerControls.hpp"

using namespace components;

PlayerControls::PlayerControls(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fCooldown = 0.5f;
    this->vecTimer = {0.f,0.f,0.f};
}

void PlayerControls::perform() {
    this->fTicks += this->tDeltaTime.asSeconds();

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
        GameSpaceUI* pGameSpaceUI = (GameSpaceUI*)GameObjectManager::getInstance()->findObjectByName("Game Space UI");
        if(pInput->isLeft()) {
            Player* pPlayer = (Player*)this->getOwner();
            GameObjectManager::getInstance()->findObjectByName("Background")->setFrame(1);
            //pPlayer->setFrontView(false);
            
        }

        if(pInput->isRight()) {
            Player* pPlayer = (Player*)this->getOwner();
            GameObjectManager::getInstance()->findObjectByName("Background")->setFrame(0);
            //pPlayer->setFrontView(true);
        }

        if(pInput->is1() && this->vecTimer[0] == 0.f){
            ItemType EType = ItemManager::getInstance()->getItem(0);
            if(EType != ItemType::NONE){
                ItemManager::getInstance()->useItem(0);
                PowerUpSystem::getInstance()->activatePowerUp(EType);
                this->vecTimer[0] = this->fCooldown * 2.f;
            }
            else{
                std::cout << "[ERROR] : No item." << std::endl;
                this->vecTimer[0] = this->fCooldown;
            }
            pGameSpaceUI->update();
        }

        if(pInput->is2() && this->vecTimer[1] == 0.f){
            ItemType EType = ItemManager::getInstance()->getItem(0);
            if(EType != ItemType::NONE){
                ItemManager::getInstance()->useItem(1);
                PowerUpSystem::getInstance()->activatePowerUp(EType);
                this->vecTimer[1] = this->fCooldown * 2.f;
            }
            else{
                std::cout << "[ERROR] : No item." << std::endl;
                this->vecTimer[1] = this->fCooldown;
            }
            pGameSpaceUI->update();
        }

        if(pInput->is3() && this->vecTimer[2] == 0.f){
            ItemType EType = ItemManager::getInstance()->getItem(0);
            if(EType != ItemType::NONE){
                ItemManager::getInstance()->useItem(2);
                PowerUpSystem::getInstance()->activatePowerUp(EType);
                this->vecTimer[2] = this->fCooldown * 2.f;
            }
            else{
                std::cout << "[ERROR] : No item." << std::endl;
                this->vecTimer[2] = this->fCooldown;
            }
            pGameSpaceUI->update();
        }

        if (pInput->isR()) {
            Player* pPlayer = (Player*)this->getOwner();

            if (pPlayer)
            {
                std::cout << "calling player start" << std::endl;
                
                pPlayer->start();
                pInput->resetR();
                SFXManager::getInstance()->getSound(SFXType::RELOAD)->play();
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
