#include "GameSpace.hpp"

using namespace scenes;

GameSpace::GameSpace() : Scene(SceneTag::GAME_SPACE) {}

GameSpace::~GameSpace() {}

void GameSpace::onLoadResources() {
    TextureManager::getInstance()->loadGameSpaceFolder();
    SFXManager::getInstance()->loadAll();
}

void GameSpace::onLoadObjects() {
    //GameObjectManager::getInstance()->findObjectByName("Game Background Side")->setEnabled(false);

    this->createUserInterface();
    this->createBackground();
    this->createNullObjectComponents();
    this->createPlayer();
    this->createItemPool();
    this->createCrosshair();
}

void GameSpace::onUnloadResources() {
    TextureManager::getInstance()->clearAll();
    SFXManager::getInstance()->unloadAll();
}

void GameSpace::onUnloadObjects() {
    Scene::onUnloadObjects();
}

void GameSpace::createNullObjectComponents() {
    std::srand(std::time(NULL));

    EmptyGameObject* pComponentHolder = new EmptyGameObject("Killer System Holder");
    PoolableKillerSystem::initialize("Poolable Killer System", pComponentHolder);
    this->registerObject(pComponentHolder);

    pComponentHolder = new EmptyGameObject("Collector System Holder");
    ItemCollectorSystem::initialize("Item Collector System", pComponentHolder);
    this->registerObject(pComponentHolder);

    pComponentHolder = new EmptyGameObject("Power Up System Holder");
    PowerUpSystem::initialize("Power Up System", pComponentHolder);
    this->registerObject(pComponentHolder);

    pComponentHolder = new EmptyGameObject("Enemy Director Holder");
    EnemyDirector* pEnemyDirector = new EnemyDirector("Enemy Director");
    pComponentHolder->attachComponent(pEnemyDirector);
    this->registerObject(pComponentHolder);

    pComponentHolder = new EmptyGameObject("View Switcher System Holder");
    ViewSwitcherSystem::initialize("View Switcher System", pComponentHolder);
    this->registerObject(pComponentHolder);
    
    EmptyGameObject* pItemSpawnLocation = new EmptyGameObject("Item Spawn Location");
    this->registerObject(pItemSpawnLocation);
}

void GameSpace::createBackground() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BACKGROUND));
    Background* pBackground = new Background("Background", pTexture);
    this->registerObject(pBackground);
}

void GameSpace::createPlayer() {
    Player* pPlayer = new Player("Player");
    this->registerObject(pPlayer);
}

void GameSpace::createUserInterface() {
    GameSpaceUI* pGameSpaceUI = new GameSpaceUI("Game Space UI");
    this->registerObject(pGameSpaceUI);
    //float nOffset = 211;

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

void GameSpace::createItemPool() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::ITEM));
    
    Item* pItem = new Item(PoolTag::ITEM, "Item", pTexture, ItemType::PWR_HEALTH);
    GameObjectPool* pItemPool = new GameObjectPool(PoolTag::ITEM, 5, pItem);
    pItemPool->initialize();

    ObjectPoolManager::getInstance()->registerObjectPool(pItemPool);
}