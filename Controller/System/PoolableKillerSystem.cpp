/* * * * * * * * * * * * * * * * * * * * * 
 *     Make this a killer system! :)     * 
 * * * * * * * * * * * * * * * * * * * * */

#include "PoolableKillerSystem.hpp"

using namespace systems;

void PoolableKillerSystem::kill(sf::Vector2f vecLocation) {
    int nKill = -1;
    float fKillThreshold = 150.f;

    EmptyGameObject* pSpawnPoint = (EmptyGameObject*)GameObjectManager::getInstance()->findObjectByName("Item Spawn Location");

    for (int i = this->vecKillable.size() - 1; i >= 0; i--) {
        Player* pPlayer = (Player*)GameObjectManager::getInstance()->findObjectByName("Player");
        bool bPlayerHasToZoom = !pPlayer->isZoomedIn() && WindowManager::getInstance()->getPartitions()->size() > 1;
        Enemy* pEnemy = (Enemy*)this->vecKillable[i]->getOwner();
        if (pEnemy->contains(vecLocation) && nKill != 1) {
            if (pEnemy->isEnabled() && pPlayer->hasBullets() && !pPlayer->getReloader()->isReloading() && !bPlayerHasToZoom) {
                
                pEnemy->decrementHealth();
                if(!PowerUpSystem::getInstance()->isActive(ItemType::PWR_PIERCE)){
                    nKill = 1;
                }
                if (pEnemy->getHealth() <= 0) {
                    this->vecKillable[i]->setKilled(true);

                    int nChance = std::rand() % 10000;
                    switch(pEnemy->getType()){
                        case EnemyType::COMMON:
                            if(nChance < COMMON_DROP_RATE * 10000){
                                
                                if(pSpawnPoint){
                                    pSpawnPoint->setPosition(this->vecKillable[i]->getOwner()->getSprite()->getPosition());
                                }
                                ObjectPoolManager::getInstance()->getPool(PoolTag::ITEM)->requestPoolable();
                            }
                            break;
                        case EnemyType::UNCOMMON:
                            if(nChance < UNCOMMON_DROP_RATE * 10000){
                                
                                if(pSpawnPoint){
                                    pSpawnPoint->setPosition(this->vecKillable[i]->getOwner()->getSprite()->getPosition());
                                }
                                ObjectPoolManager::getInstance()->getPool(PoolTag::ITEM)->requestPoolable();
                            }
                            break;
                        case EnemyType::ELITE:
                            if(nChance < ELITE_DROP_RATE * 10000){
                                
                                if(pSpawnPoint){
                                    pSpawnPoint->setPosition(this->vecKillable[i]->getOwner()->getSprite()->getPosition());
                                }
                                ObjectPoolManager::getInstance()->getPool(PoolTag::ITEM)->requestPoolable();
                            }
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }
    if(PowerUpSystem::getInstance()->isActive(ItemType::PWR_PIERCE)){
        PowerUpSystem::getInstance()->clearPowerUp(ItemType::PWR_PIERCE);
    }
}

void PoolableKillerSystem::hit() {
    float fKillThreshold = 150.f;

    //EmptyGameObject* pSpawnPoint = (EmptyGameObject*)GameObjectManager::getInstance()->findObjectByName("Item Spawn Location");
    Player* pPlayer = (Player*)GameObjectManager::getInstance()->findObjectByName("Player");
    for (int i = 0; i < this->vecKillable.size(); i++) {
        if (this->vecKillable[i]->getOwner()->getZ() <= 0.0f) {
            if (!this->vecKillable[i]->isKilled()) {
                pPlayer->decrementHealth();
                this->vecKillable[i]->getOwner()->setZ(1920.f);
                this->vecKillable[i]->setKilled(true);
            }
        }
    }
    if (pPlayer->getHealth() <= 0)
        this->playerDeath();
}

void PoolableKillerSystem::perform() {
    Crosshair* pCrosshair = (Crosshair*)GameObjectManager::getInstance()->findObjectByName("Crosshair");
    if(pCrosshair == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        CrosshairMouseInput* pCrosshairMouseInput = (CrosshairMouseInput*)pCrosshair->findComponentByName("Crosshair Mouse Input");
        
        if(pCrosshairMouseInput == NULL) {
            std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
        }
        else {
            if(pCrosshairMouseInput->isLeftClick()) {
                std::cout << "pCrosshairMouseInput left click in poolablekillersystem" << std::endl;
                Player* pPlayer = (Player*)GameObjectManager::getInstance()->findObjectByName("Player");
                GameSpaceUI* pGameSpaceUI = (GameSpaceUI*)GameObjectManager::getInstance()->findObjectByName("Game Space UI");

                if (!pPlayer)
                    std::cout << "pPlayer doesn't exist" << std::endl;

                if (!pGameSpaceUI)
                    std::cout << "pGameSpaceUI doesn't exist" << std::endl;

                std::cout << "proceeding in poolablekillersystem" << std::endl;

                ItemCollectorSystem::getInstance()->collect(pCrosshairMouseInput->getLocation());
                bool isBlocked = false;

                if(!PowerUpSystem::getInstance()->isActive(ItemType::PWR_PIERCE)){
                    std::vector<PoolableObject*> vecPool = BlockerManager::getInstance()->getBlockers();
                    for(int i = 0; i < vecPool.size() && !isBlocked; i++){
                        Blocker* pBlocker = (Blocker*)vecPool[i];
                        if(pBlocker){
                            if(pBlocker->contains(pCrosshairMouseInput->getLocation())){
                                isBlocked = true;
                                
                                if(pPlayer->hasBullets())
                                    SFXManager::getInstance()->getSound(SFXType::BLOCKER)->play();
                            }
                        }
                    }
                }
                
                if(!isBlocked || PowerUpSystem::getInstance()->isActive(ItemType::PWR_PIERCE)){
                    this->kill(pCrosshairMouseInput->getLocation());
                }
                
                //This was moved from CrosshairMouseInput.cpp because otherwise the last bullet wont hit
                //This is like really bad. like really really bad. but hey it works...
                if(pPlayer->hasBullets()){
                    pPlayer->decrementBullets();
                    pGameSpaceUI->update();
                }

                pCrosshairMouseInput->resetLeftClick();
                std::cout << "if statement over" << std::endl;
            }
            this->hit();
            std::cout << "hit statement over" << std::endl;
        }
    }
}

void PoolableKillerSystem::playerDeath() {
    if (!ViewManager::getInstance()->getView(ViewTag::GAME_OVER_SCREEN)->isEnabled())
    {
        ((Timer*)(GameObjectManager::getInstance()->findObjectByName("Game Space UI")->findComponentByName("Game Space UI Timer")))->stop();

        std::ofstream scores("File/scores.txt", std::ios::app);
        float currentTime = ((Timer*)(GameObjectManager::getInstance()->findObjectByName("Game Space UI")->findComponentByName("Game Space UI Timer")))->getTime();
        scores << currentTime << std::endl;
        scores.close();

    }

    WindowManager::getInstance()->getWindow()->setView(WindowManager::getInstance()->getWindow()->getDefaultView());
    ViewManager::getInstance()->getView(ViewTag::GAME_OVER_SCREEN)->setEnabled(true);
    // std::exit(69);
}

void PoolableKillerSystem::registerComponent(Killable* pKillable) {
    this->vecKillable.push_back(pKillable);
}

void PoolableKillerSystem::unregisterComponent(Killable* pKillable) {
    int nIndex = -1;

    for(int i = 0; i < this->vecKillable.size() && nIndex == -1; i++) {
        if(this->vecKillable[i] == pKillable)
            nIndex = i;
    }

    if(nIndex != -1) {
        this->vecKillable.erase(this->vecKillable.begin() + nIndex);
    }
}

/* * * * * * * * * * * * * * * * * * * * * 
 *       SINGLETON-RELATED CONTENT       * 
 * * * * * * * * * * * * * * * * * * * * */

PoolableKillerSystem* PoolableKillerSystem::P_SHARED_INSTANCE = NULL;
PoolableKillerSystem::PoolableKillerSystem(std::string strName) : Component(strName, ComponentType::SCRIPT) {}
PoolableKillerSystem::PoolableKillerSystem(const PoolableKillerSystem& CObject) : Component(CObject.strName, ComponentType::SCRIPT) {}

PoolableKillerSystem* PoolableKillerSystem::getInstance() {
    return P_SHARED_INSTANCE;
}

void PoolableKillerSystem::initialize(std::string strName, GameObject* pParent) {
    P_SHARED_INSTANCE = new PoolableKillerSystem(strName);
    pParent->attachComponent(P_SHARED_INSTANCE);
}
