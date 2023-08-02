#include "Player.hpp"

using namespace models;

Player::Player(std::string strName) : GameObject(strName) {
    
}

Player::~Player() {}

void Player::initialize() {
    this->nHealth = 5;
    this->nBullets = 5;

    PlayerInput* pInputComponent = new PlayerInput(this->strName + " Input");
    PlayerControls* pControlsComponent = new PlayerControls(this->strName + " Controls");
    this->attachComponent(pInputComponent);
    this->attachComponent(pControlsComponent);
}