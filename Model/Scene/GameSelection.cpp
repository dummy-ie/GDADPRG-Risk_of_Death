#include "GameSelection.hpp"

using namespace scenes;

GameSelection::GameSelection() : Scene(SceneTag::GAME_SELECTION) {}

GameSelection::~GameSelection() {}

void GameSelection::onLoadResources() {
    TextureManager::getInstance()->loadGameMenuFolder();
}

void GameSelection::onLoadObjects() {
    this->createBackground();

    this->createUserInterface();
}

void GameSelection::onUnloadResources() {
    TextureManager::getInstance()->clearAll();
}

void GameSelection::onUnloadObjects() {
    Scene::onUnloadObjects();
}

void GameSelection::createBackground() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BACKGROUND));

    Background* pBackground = new Background("Background", pTexture);
    this->registerObject(pBackground);
}

void GameSelection::createUserInterface() {
    SelectionScreen* pSelectionScreen = new SelectionScreen("Selection Screen");
    this->registerObject(pSelectionScreen);
}