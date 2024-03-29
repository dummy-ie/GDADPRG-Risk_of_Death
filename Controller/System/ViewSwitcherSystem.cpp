/* * * * * * * * * * * * * * * * * * * * * 
 *     Make this a killer system! :)     * 
 * * * * * * * * * * * * * * * * * * * * */

#include "ViewSwitcherSystem.hpp"

using namespace systems;

void ViewSwitcherSystem::switchLeftView() {
    for (Switcher* pSwitcher : this->vecSwitcher) {
        pSwitcher->switchLeftView();
    }
}

void ViewSwitcherSystem::switchFrontView() {
    for (Switcher* pSwitcher : this->vecSwitcher) {
        pSwitcher->switchFrontView();
    }
}

void ViewSwitcherSystem::perform() {
    Player* pPlayer = (Player*)GameObjectManager::getInstance()->findObjectByName("Player");
    if(pPlayer == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        PlayerInput* pPlayerInput = pPlayer->getInput();
        if(pPlayerInput == NULL) {
            std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
        }
        else {
            if(pPlayerInput->isLeft() && !pPlayer->isZoomedIn()) {
                this->bSort = true;
                this->bFront = false;
            }
            if(pPlayerInput->isRight()) {
                this->bSort = true;
                this->bFront = true;
            }
            if (bFront) {
                if (bSort) {
                    GameObjectManager::getInstance()->sortObjectsByZ();
                    this->bSort = false;
                }
                this->switchFrontView();
            }
            else {
                if (bSort) {
                    GameObjectManager::getInstance()->sortObjectsByX();
                    this->bSort = false;
                }
                this->switchLeftView();
            }
        }
    }
}

void ViewSwitcherSystem::registerComponent(Switcher* pSwitcher) {
    this->vecSwitcher.push_back(pSwitcher);
}

void ViewSwitcherSystem::unregisterComponent(Switcher* pSwitcher) {
    int nIndex = -1;

    for(int i = 0; i < this->vecSwitcher.size() && nIndex == -1; i++) {
        if(this->vecSwitcher[i] == pSwitcher)
            nIndex = i;
    }

    if(nIndex != -1) {
        this->vecSwitcher.erase(this->vecSwitcher.begin() + nIndex);
    }
}

void ViewSwitcherSystem::clearAll(){
    this->vecSwitcher.clear();
}

ViewSwitcherSystem* ViewSwitcherSystem::P_SHARED_INSTANCE = NULL;
ViewSwitcherSystem::ViewSwitcherSystem(std::string strName) : Component(strName, ComponentType::SCRIPT) {}
ViewSwitcherSystem::ViewSwitcherSystem(const ViewSwitcherSystem& CObject) : Component(CObject.strName, ComponentType::SCRIPT) {}

ViewSwitcherSystem* ViewSwitcherSystem::getInstance() {
    return P_SHARED_INSTANCE;
}

void ViewSwitcherSystem::initialize(std::string strName, GameObject* pParent) {
    P_SHARED_INSTANCE = new ViewSwitcherSystem(strName);
    pParent->attachComponent(P_SHARED_INSTANCE);
}
