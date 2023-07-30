#include "GameSpace.hpp"

using namespace scenes;

GameSpace::GameSpace() : Scene(SceneTag::GAME_SPACE) {}

GameSpace::~GameSpace() {}

void GameSpace::onLoadResources() {
    
}

void GameSpace::onLoadObjects() {
    this->createBackground("Game Background Front", AssetType::GAME_BACKGROUND_FRONT);
    this->createBackground("Game Background Side", AssetType::GAME_BACKGROUND_SIDE);
    GameObjectManager::getInstance()->findObjectByName("Game Background Side")->setEnabled(false);

    this->createNullObjectComponents();
    this->createUserInterface();
    this->createCrosshair();


}

void GameSpace::onUnloadResources() {
    
}

void GameSpace::createNullObjectComponents() {
    std::srand(std::time(NULL));

    EmptyGameObject* pComponentHolder = new EmptyGameObject("Enemy Director Holder");
    EnemyDirector* pEnemyDirector = new EnemyDirector("Enemy Director");
    pComponentHolder->attachComponent(pEnemyDirector);
    GameObjectManager::getInstance()->addObject(pComponentHolder);
}

void GameSpace::createBackground(std::string strName, AssetType EType) {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(EType));
    Background* pBackground = new Background(strName, pTexture);
    this->registerObject(pBackground);
}

void GameSpace::createUserInterface() {
    PlayerUI* pPlayerUI = new PlayerUI("Player UI");
    this->registerObject(pPlayerUI);
    float nOffset = 211;

    //for (int i = 0; i < 10; i++) {
    //    int nTemp = static_cast<int>(AssetType::GREEN_SLIME_1) + i;
    //    AssetType EType = static_cast<AssetType>(nTemp);
    //    //pTexture->loadFromFile("View/Image/slimesheet.png", sf::IntRect(0 + (nOffset * i), 0, 212, 159));
    //    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(EType));
    //    std::string strName = "Enemy " + std::to_string(i + 1);
    //    Enemy* pEnemy = new Enemy(strName, pTexture, EnemyType::COMMON, 0.f + (nOffset * i), 11.f);
    //    this->registerObject(pEnemy);
    //}
}

void GameSpace::createCrosshair() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::CROSSHAIR));
    Crosshair* pCrosshair = new Crosshair("Crosshair", pTexture);
    this->registerObject(pCrosshair);
}