#include "Switcher.hpp"

using namespace components;

Switcher::Switcher(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fTicks = 0.0f;
}

void Switcher::perform() {
    /*float fFrameInterval = 0.01f;

    if (this->bSwitching) {
        this->fTicks += this->tDeltaTime.asSeconds();
        if (this->fTicks >= fFrameInterval) {
            this->fTicks = 0.0f;
            this->switchView();
            this->stop();
        }
    }*/
}

/*void Switcher::switchView() {
    if(this->pSwitchable == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        this->pSwitchable->switchView();
    }
}*/

void Switcher::start() {
    this->bSwitching = true;
}

void Switcher::stop() {
    this->bSwitching = false;
}

void Switcher::switchLeftView() {
    this->pSwitchable->switchLeftView();
}

void Switcher::switchFrontView() {
    this->pSwitchable->switchFrontView();

}

void Switcher::setSwitchable(Switchable* pSwitchable) {
    this->pSwitchable = pSwitchable;

}