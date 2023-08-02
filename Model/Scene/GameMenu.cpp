#include "GameMenu.hpp"

using namespace scenes;

GameMenu::GameMenu() : Scene(SceneTag::GAME_MENU) {}

GameMenu::~GameMenu() {}

void GameMenu::onLoadResources() {
    TextureManager::getInstance()->loadGameMenuFolder();
}

void GameMenu::onLoadObjects() {
    this->createBackground();

    this->createUserInterface();
}

void GameMenu::onUnloadResources() {
    TextureManager::getInstance()->clearAll();
}

void GameMenu::onUnloadObjects() {
    Scene::onUnloadObjects();
}

void GameMenu::createBackground() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BACKGROUND));

    Background* pBackground = new Background("Background", pTexture);
    this->registerObject(pBackground);
}

void GameMenu::createUserInterface() {
    TitleScreen* pTitleScreen = new TitleScreen("Title Screen");
    this->registerObject(pTitleScreen);
}