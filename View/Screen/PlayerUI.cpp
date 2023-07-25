#include "PlayerUI.hpp"

using namespace views;

PlayerUI::PlayerUI(std::string strName) : View(ViewTag::PLAYER_UI, strName) {
    ViewManager::getInstance()->registerView(this);
}

PlayerUI::~PlayerUI() {}

void PlayerUI::initialize() {
    PlayerInput* pInputComponent = new PlayerInput(this->strName + " Input");
    PlayerControls* pControlsComponent = new PlayerControls(this->strName + " Controls");
    this->attachComponent(pInputComponent);
    this->attachComponent(pControlsComponent);
}

void PlayerUI::decrementHealth() {}

void PlayerUI::decrementBullets() {}