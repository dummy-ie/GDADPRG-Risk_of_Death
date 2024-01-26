#include "Player.hpp"

using namespace models;

Player::Player(std::string strName) : GameObject(strName) {
    this->nHealth = 5;
    this->nBullets = 5 * WindowManager::getInstance()->getPartitions()->size();
}

Player::~Player() {}

void Player::initialize() {
    this->nHealth = 5;
    this->nBullets = 5 * WindowManager::getInstance()->getPartitions()->size();
    //this->bFrontView = true;

    this->pPlayerInput = new PlayerInput(this->strName + " Input");
    PlayerControls* pControlsComponent = new PlayerControls(this->strName + " Controls");
    this->attachComponent(this->pPlayerInput);
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
    this->nBullets = 5 * WindowManager::getInstance()->getPartitions()->size();
    GameSpaceUI* pGameSpaceUI = (GameSpaceUI*)GameObjectManager::getInstance()->findObjectByName("Game Space UI");
    pGameSpaceUI->update();
}

void Player::randomIncrementHealth() {
    this->nHealth += (std::rand()%3) + 1;
    GameSpaceUI* pGameSpaceUI = (GameSpaceUI*)GameObjectManager::getInstance()->findObjectByName("Game Space UI");
    pGameSpaceUI->update();
}

void Player::decrementHealth()
{
    if(!PowerUpSystem::getInstance()->isActive(ItemType::PWR_INVINCIBILITY) && this->nHealth >= 0){
        this->nHealth--;
    }
    GameSpaceUI* pGameSpaceUI = (GameSpaceUI*)GameObjectManager::getInstance()->findObjectByName("Game Space UI");
    pGameSpaceUI->update();

    SFXManager::getInstance()->getSound(SFXType::HURT)->play();
}

void Player::decrementBullets()
{
    if(!PowerUpSystem::getInstance()->isActive(ItemType::PWR_INVINCIBILITY)){
        this->nBullets--;
    }
    GameSpaceUI* pGameSpaceUI = (GameSpaceUI*)GameObjectManager::getInstance()->findObjectByName("Game Space UI");
    pGameSpaceUI->update();
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

/*void Player::setFrontView(bool bFrontView) {
    this->bFrontView = bFrontView;
}*/

int Player::getHealth() {
    return this->nHealth;
}

int Player::getBullets() {
    return this->nBullets;
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

PlayerInput* Player::getInput() {
    return this->pPlayerInput;
}

void Player::setHealth(int nHealth) {
    this->nHealth = nHealth;
}