#include "Reloader.hpp"

using namespace components;

Reloader::Reloader(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->pReloadable = NULL;
    this->bReloading = false;

    this->fFrameInterval = 1.0f;
    this->fTicks = 0.0f;
}

void Reloader::perform() {
    // if (this->pReloadable)
    //     std::cout << "reloader performing " << bReloading << std::endl;

    if (this->bReloading) {
        std::cout << "reloader performing " << bReloading << std::endl;
        this->fTicks += this->tDeltaTime.asSeconds() * GAME_SPEED;

        if (this->fTicks >= this->fFrameInterval) {
            this->fTicks = 0.0f;
            this->reload();
            this->stop();
        }
    }
}

void Reloader::start() {
    this->bReloading = true;
    std::cout << "bReloading now true (crash)" << std::endl;
}

void Reloader::stop() {
    this->bReloading = false;
}

void Reloader::reload() {
    if(this->pReloadable == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        std::cout << "trying to call pReloadable reload()" << std::endl;
        this->pReloadable->reload();
    }
}

void Reloader::setReloadable(Reloadable* pReloadable) {
    this->pReloadable = pReloadable;
}

bool Reloader::isReloading() {
    return this->bReloading;
}
