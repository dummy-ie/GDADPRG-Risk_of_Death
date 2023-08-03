#include "EnemyDirector.hpp"

using namespace directors;

EnemyDirector::EnemyDirector(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fUpdateInterval = 8.0f;
    this->fUpdateTicks = 0.0f;
    this->fTicks = 0.0f;

    this->createEnemyPool(PoolTag::GREEN_SLIME, 20, EnemyType::COMMON, AssetType::GREEN_SLIME);
    this->createEnemyPool(PoolTag::PURPLE_SLIME, 10, EnemyType::UNCOMMON, AssetType::PURPLE_SLIME);
    //this->createEnemyPool(PoolTag::YELLOW_SLIME, 3, EnemyType::COMMON, AssetType::YELLOW_SLIME);
    this->createEnemyPool(PoolTag::RED_SLIME, 5, EnemyType::ELITE, AssetType::RED_SLIME);
    //this->createEnemyPool(PoolTag::BLUE_SLIME, 3, EnemyType::COMMON, AssetType::BLUE_SLIME);
}

EnemyDirector::~EnemyDirector() {}

void EnemyDirector::createEnemyPool(PoolTag ETag, int nPoolSize, EnemyType EType, AssetType ETexture) {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(ETexture));

    Enemy* pEnemy = new Enemy(ETag, "Slime", pTexture, EType);
    GameObjectPool* pGameObjectPool = new GameObjectPool(ETag, nPoolSize, pEnemy);
    pGameObjectPool->initialize();
    ObjectPoolManager::getInstance()->registerObjectPool(pGameObjectPool);
}

void EnemyDirector::spawnWave() {
    int nEnemySpawnCount = this->fTicks * /*subscreen count*/1.0f;
    float fLuck = (float)nEnemySpawnCount * randomizePercent(0.20f);
    nEnemySpawnCount -= fLuck;

    float fSpawnDecay = 0.02f * (this->fTicks / 5.0f);
    float fCommonSpawn = 0.7f - fSpawnDecay;
    float fUncommonSpawn = (1 - fCommonSpawn) * 0.6f;
    float fEliteSpawn = 1 - (fCommonSpawn + fUncommonSpawn);

    int nCommon = fCommonSpawn * nEnemySpawnCount;
    int nUncommon = fUncommonSpawn * nEnemySpawnCount;
    int nElite = fEliteSpawn * nEnemySpawnCount;

    ObjectPoolManager::getInstance()->getPool(PoolTag::GREEN_SLIME)->requestPoolableBatch(nCommon);
    ObjectPoolManager::getInstance()->getPool(PoolTag::PURPLE_SLIME)->requestPoolableBatch(nUncommon);
    ObjectPoolManager::getInstance()->getPool(PoolTag::RED_SLIME)->requestPoolableBatch(nElite);
}

float EnemyDirector::randomizePercent(float fMax) {
    int nMax = fMax * 100;
    int nRandom = (std::rand() % nMax);
    std::cout << (float)nRandom / 100.f << std::endl;
    return (float)nRandom / 100.f;
} 

void EnemyDirector::perform() {
    this->fTicks += this->tDeltaTime.asSeconds() * GAME_SPEED;
    this->fUpdateTicks += this->tDeltaTime.asSeconds() * GAME_SPEED;
    if(this->fUpdateTicks > this->fUpdateInterval) {
        this->fUpdateTicks = 0.0f;
        this->spawnWave();
    }
}
