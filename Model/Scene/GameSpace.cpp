#include "GameSpace.hpp"

using namespace scenes;

GameSpace::GameSpace() : Scene(SceneTag::GAME_SPACE) {}

GameSpace::~GameSpace() {}

void GameSpace::onLoadResources() {
    
}

void GameSpace::onLoadObjects() {
    this->createBackground("Game Background Front", AssetType::GAME_BACKGROUND_FRONT);
    this->createBackground("Game Background Side", AssetType::GAME_BACKGROUND_SIDE);
    GameObjectManager::getInstance()->findObjectByName("Game Background Side")->setEnabled(false);

    this->createUserInterface();
    this->createCrosshair();
}

void GameSpace::onUnloadResources() {
    
}

void GameSpace::createBackground(std::string strName, AssetType EType) {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(EType));
    Background* pBackground = new Background(strName, pTexture);
    this->registerObject(pBackground);
}

void GameSpace::createUserInterface() {
    PlayerUI* pPlayerUI = new PlayerUI("Player UI");
    this->registerObject(pPlayerUI);
}

void GameSpace::createCrosshair() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::CROSSHAIR));
    Crosshair* pCrosshair = new Crosshair("Crosshair", pTexture);
    this->registerObject(pCrosshair);
}