#include "GameSpaceUI.hpp"

using namespace views;

GameSpaceUI::GameSpaceUI(std::string strName) : View(ViewTag::GAME_SPACE_UI, strName) {
    ViewManager::getInstance()->registerView(this);
}

GameSpaceUI::~GameSpaceUI() {}

void GameSpaceUI::initialize() {
    PlayerInput* pInputComponent = new PlayerInput(this->strName + " Input");
    PlayerControls* pControlsComponent = new PlayerControls(this->strName + " Controls");
    this->attachComponent(pInputComponent);
    this->attachComponent(pControlsComponent);
}