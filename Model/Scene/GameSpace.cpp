#include "GameSpace.hpp"

using namespace scenes;

GameSpace::GameSpace() : Scene(SceneTag::GAME_SPACE) {}

GameSpace::~GameSpace() {}

void GameSpace::onLoadResources() {
    
}

void GameSpace::onLoadObjects() {
    this->createBackground();
}

void GameSpace::onUnloadResources() {
    
}

void GameSpace::createBackground() {
    AssetType EType = AssetType::GAME_BACKGROUND_FRONT;
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(EType));

    Background* pBackground = new Background("Game Background Front", pTexture);
    this->registerObject(pBackground);
}