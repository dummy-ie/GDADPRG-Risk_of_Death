#include "GameLeaderboard.hpp"

using namespace scenes;

GameLeaderboard::GameLeaderboard() : Scene(SceneTag::GAME_LEADERBOARD) {}

GameLeaderboard::~GameLeaderboard() {}

void GameLeaderboard::onLoadResources() {
    TextureManager::getInstance()->loadGameMenuFolder();
}

void GameLeaderboard::onLoadObjects() {
    this->createBackground();

    this->createUserInterface();
}

void GameLeaderboard::onUnloadResources() {
    TextureManager::getInstance()->clearAll();
}

void GameLeaderboard::onUnloadObjects() {
    Scene::onUnloadObjects();
}

void GameLeaderboard::createBackground() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BACKGROUND));

    Background* pBackground = new Background("Background", pTexture);
    this->registerObject(pBackground);
}

void GameLeaderboard::createUserInterface() {
    LeaderboardScreen* pLeaderboardScreen = new LeaderboardScreen("Leaderboard Screen");
    this->registerObject(pLeaderboardScreen);
}