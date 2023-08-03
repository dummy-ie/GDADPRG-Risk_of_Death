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

    Player* pPlayer = (Player*)GameObjectManager::getInstance()->findObjectByName("Player");
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::HEART));
    //this->pHeart = 
    this->createImage(this->strName + " Heart", pTexture, 0.05f, 75.f, SCREEN_HEIGHT - 75.f);

    this->pHealth = new Text(this->strName + " Health", std::to_string(pPlayer->getHealth()), FontManager::getInstance()->getFont(FontType::DEFAULT));
    this->attachChild(this->pHealth);
    this->pHealth->setPosition(sf::Vector2f(125.f, SCREEN_HEIGHT - 90.f));

    pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BULLET));
    this->createImage(this->strName + " Bullet", pTexture, 0.15f, 75.f, SCREEN_HEIGHT - 150.f);

    this->pBullets = new Text(this->strName + " Bullets", std::to_string(pPlayer->getBullets()), FontManager::getInstance()->getFont(FontType::DEFAULT));
    this->attachChild(this->pBullets);
    this->pBullets->setPosition(sf::Vector2f(125.f, SCREEN_HEIGHT - 165.f));
}

void GameSpaceUI::update() {
    Player* pPlayer = (Player*)GameObjectManager::getInstance()->findObjectByName("Player");
    this->pHealth->setText(std::to_string(pPlayer->getHealth()));
    this->pBullets->setText(std::to_string(pPlayer->getBullets()));
}