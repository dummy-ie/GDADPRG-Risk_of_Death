#include "Player.hpp"

using namespace models;

Player::Player(std::string strName) : GameObject(strName) {
    this->nHealth = 5;
    this->nBullets = 5;
}

Player::~Player() {}

void Player::initialize() {
    PlayerInput* pInputComponent = new PlayerInput(this->strName + " Input");
    PlayerControls* pControlsComponent = new PlayerControls(this->strName + " Controls");
    this->attachComponent(pInputComponent);
    this->attachComponent(pControlsComponent);

    this->pReloader = new Reloader(this->strName + " Reloader");
    this->pReloader->setReloadable(this);
    this->attachComponent(this->pReloader); 
}

void Player::start() {
    if(this->pReloader != NULL) {
        std::cout << "calling pReloader start()" << std::endl;
        this->pReloader->start();
    }
}

void Player::stop() {
    if (this->pReloader != NULL) {
        this->pReloader->stop();
    }
}

void Player::reload() {
    this->nBullets = 5;
}

void Player::decrementHealth()
{
    this->nHealth--;
}

void Player::decrementBullets()
{
    this->nBullets--;
}

void Player::setZoomedIn(bool bIsZoomedIn)
{
    this->bIsZoomedIn = bIsZoomedIn;

    if (!this->bIsZoomedIn)
        WindowManager::getInstance()->getWindow()->setView(WindowManager::getInstance()->getWindow()->getDefaultView());        
}

bool models::Player::isZoomedIn()
{
    return this->bIsZoomedIn;
}

bool Player::hasBullets()
{
    if (this->nBullets > 0)
        return true;
    return false;
}

Reloader* Player::getReloader() {
    return this->pReloader;
}