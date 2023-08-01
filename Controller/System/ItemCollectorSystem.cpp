/* * * * * * * * * * * * * * * * * * * * * 
 *     Make this a killer system! :)     * 
 * * * * * * * * * * * * * * * * * * * * */

#include "ItemCollectorSystem.hpp"

using namespace systems;

/* [NOTE] : This Component is a type of [System]. It has a vector attribute that contains
            ALL [Killable] Components in the game.

            This Component listens to [CrosshairMouseInput] LEFT clicks. Once detected,
            It calls its [this->kill()] method to enable the correct [Killable] Component.

            Enabling a [Killable] Component is done by setting its [bKilled] attribute
            to TRUE (i.e [setKilled(true)]).
*/

void ItemCollectorSystem::collect(sf::Vector2f vecLocation) {
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
    int nCollect = -1;
    float fCollectThreshold = 150.f;

    for (int i = this->vecCollectable.size() - 1; i >= 0; i--) {
        float fDistance = sqrt(pow(vecLocation.x - this->vecCollectable[i]->getOwner()->getSprite()->getPosition().x, 2) + pow(vecLocation.y - this->vecCollectable[i]->getOwner()->getSprite()->getPosition().y, 2));
        if (fDistance < fCollectThreshold && nCollect != 1) {
            if (this->vecCollectable[i]->getOwner()->isEnabled()) {
                //this->vecKillable[i]->getOwner()->setAnimationType(AnimationType::KILLED);
                this->vecCollectable[i]->setCollected(true);
                nCollect = 1;
            }
        }
    }
    /*for (Killable* pKillable : this->vecKillable) {
        fDistance = sqrt(pow(vecLocation.x - pKillable->getOwner()->getSprite()->getPosition().x, 2) + pow(vecLocation.y - pKillable->getOwner()->getSprite()->getPosition().y, 2));
        if (fDistance < fKillThreshold && nKill != 1) {
            if (pKillable->getOwner()->isEnabled()) {
                pKillable->getOwner()->setAnimationType(AnimationType::KILLED);
                pKillable->setKilled(true);
                nKill = 1;
            }
        }
    }*/
}

void ItemCollectorSystem::perform() {
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
                this->collect(pCrosshairMouseInput->getLocation());

                /* It is important to force the click back to FALSE, to prevent multiple
                   triggers when the LEFT click is held. */
                pCrosshairMouseInput->resetLeftClick();
            }
        }
    }
}

/* Register a [Killable*] Component to the System. */
void ItemCollectorSystem::registerComponent(Collectable* pCollectable) {
    this->vecCollectable.push_back(pCollectable);
}

/* Unregister a [Killable*] Component from the System.
   This isn't actually used in the program yet. */
void ItemCollectorSystem::unregisterComponent(Collectable* pCollectable) {
    int nIndex = -1;

    for(int i = 0; i < this->vecCollectable.size() && nIndex == -1; i++) {
        if(this->vecCollectable[i] == pCollectable)
            nIndex = i;
    }

    if(nIndex != -1) {
        this->vecCollectable.erase(this->vecCollectable.begin() + nIndex);
    }
}

/* * * * * * * * * * * * * * * * * * * * * 
 *       SINGLETON-RELATED CONTENT       * 
 * * * * * * * * * * * * * * * * * * * * */

ItemCollectorSystem* ItemCollectorSystem::P_SHARED_INSTANCE = NULL;
ItemCollectorSystem::ItemCollectorSystem(std::string strName) : Component(strName, ComponentType::SCRIPT) {}
ItemCollectorSystem::ItemCollectorSystem(const ItemCollectorSystem& CObject) : Component(CObject.strName, ComponentType::SCRIPT) {}

ItemCollectorSystem* ItemCollectorSystem::getInstance() {
    return P_SHARED_INSTANCE;
}

void ItemCollectorSystem::initialize(std::string strName, GameObject* pParent) {
    P_SHARED_INSTANCE = new ItemCollectorSystem(strName);
    pParent->attachComponent(P_SHARED_INSTANCE);
}
