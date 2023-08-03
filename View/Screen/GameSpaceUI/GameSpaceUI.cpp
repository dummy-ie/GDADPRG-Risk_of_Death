#include "GameSpaceUI.hpp"

using namespace views;

GameSpaceUI::GameSpaceUI(std::string strName) : View(ViewTag::GAME_SPACE_UI, strName) {
    ViewManager::getInstance()->registerView(this);
    this->pGameTimer = NULL;
}

GameSpaceUI::~GameSpaceUI() {}

void GameSpaceUI::initialize() {
    this->pGameTimer = new GameTimer(this->strName + " Game Timer");
    this->attachChild(pGameTimer);
    this->pGameTimer->setEnabled(true);
}