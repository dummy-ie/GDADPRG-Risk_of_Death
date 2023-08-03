/* * * * * * * * * * * * * * * * * * * * * 
 *     Make this a killer system! :)     * 
 * * * * * * * * * * * * * * * * * * * * */

#include "PoolableKillerSystem.hpp"

using namespace systems;

/* [NOTE] : This Component is a type of [System]. It has a vector attribute that contains
            ALL [Killable] Components in the game.

            This Component listens to [CrosshairMouseInput] LEFT clicks. Once detected,
            It calls its [this->kill()] method to enable the correct [Killable] Component.

            Enabling a [Killable] Component is done by setting its [bKilled] attribute
            to TRUE (i.e [setKilled(true)]).
*/

void PoolableKillerSystem::kill(sf::Vector2f vecLocation) {
    /* [TODO] : Check if there is an object in [vecLocation]. If so, KILL (a.k.a RELEASE) that object.
                Make sure to check the following :
                    [1] Only KILL the object if it is ENABLED.
                    [2] Only KILL the object if it is NOT currently playing its [Killable] animation.
                    [3] Only KILL the object that is drawn at the VERY TOP. */

    /* [IMPORTANT] : Do [this->pOwner->setAnimationType(AnimationType::KILLED)] BEFORE you do
                     [this->vecKillable[?]->setKilled(true)]. This switches the GameObject's
                     [AnimatedTexture] to the KILLED version as opposed to the IDLE version.
                     
                     Calling [incrementFrame()] in the resulting [Killable] Component's
                     [perform()] will then display and increment the KILLED version. */
    int nKill = -1;
    float fKillThreshold = 150.f;

    for (int i = this->vecKillable.size() - 1; i >= 0; i--) {
        float fDistance = sqrt(pow(vecLocation.x - this->vecKillable[i]->getOwner()->getSprite()->getPosition().x, 2) + pow(vecLocation.y - this->vecKillable[i]->getOwner()->getSprite()->getPosition().y, 2));
        // Change this to if hitbox (not yet implemented) contains vecLocation
        Player* pPlayer = (Player*)GameObjectManager::getInstance()->findObjectByName("Player");
        bool bPlayerHasToZoom = !pPlayer->isZoomedIn() && WindowManager::getInstance()->getPartitions()->size() > 1;
        if (fDistance < fKillThreshold && nKill != 1) {
            Enemy* pEnemy = (Enemy*)this->vecKillable[i]->getOwner();
            if (pEnemy->isEnabled() && pPlayer->isZoomedIn() && pPlayer->hasBullets() && !pPlayer->getReloader()->isReloading() && !bPlayerHasToZoom) {
                pEnemy->decrementHealth();
                if (pEnemy->getHealth() <= 0) {
                    this->vecKillable[i]->setKilled(true);
                    if(!PowerUpSystem::getInstance()->isActive(ItemType::PWR_PIERCE)){
                        nKill = 1;
                    }
                }
            }
        }
    }
    if(PowerUpSystem::getInstance()->isActive(ItemType::PWR_PIERCE)){
        PowerUpSystem::getInstance()->clearPowerUp(ItemType::PWR_PIERCE);
    }
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
            /* Listen for LEFT clicks. */
            if(pCrosshairMouseInput->isLeftClick()) {
                
                /* When a LEFT click is detected, call [this->kill()], passing the location of the click. */
                this->kill(pCrosshairMouseInput->getLocation());

                /* It is important to force the click back to FALSE, to prevent multiple
                   triggers when the LEFT click is held. */
                pCrosshairMouseInput->resetLeftClick();
            }
        }
    }
}

/* Register a [Killable*] Component to the System. */
void PoolableKillerSystem::registerComponent(Killable* pKillable) {
    this->vecKillable.push_back(pKillable);
}

/* Unregister a [Killable*] Component from the System.
   This isn't actually used in the program yet. */
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
