#include "EnemyDirector.hpp"

using namespace directors;

EnemyDirector::EnemyDirector(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fUpdateInterval = 8.0f;
    this->fUpdateTicks = 0.0f;
    this->fTicks = 0.0f;

    for (Enemy *pEnemy : EnemyManager::getInstance()->getAllType(EnemyType::COMMON))
        this->createEnemyPool(6, pEnemy);
    for (Enemy *pEnemy : EnemyManager::getInstance()->getAllType(EnemyType::UNCOMMON))
        this->createEnemyPool(3, pEnemy);
    for (Enemy *pEnemy : EnemyManager::getInstance()->getAllType(EnemyType::ELITE))
        this->createEnemyPool(2, pEnemy);
}

EnemyDirector::~EnemyDirector() {}

void EnemyDirector::createEnemyPool(int nPoolSize, Enemy* pEnemy) {
    GameObjectPool* pGameObjectPool = new GameObjectPool(pEnemy->getTag(), nPoolSize, pEnemy);
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

    for (int i = 0; i < nCommon; i++) {
        ObjectPoolManager::getInstance()->getPool(PoolTag::GREEN_SLIME)->requestPoolable();

    }
    for (int i = 0; i < nUncommon; i++) {
        ObjectPoolManager::getInstance()->getPool(PoolTag::PURPLE_SLIME)->requestPoolable();

    }
    for (int i = 0; i < nElite; i++) {
        ObjectPoolManager::getInstance()->getPool(PoolTag::RED_SLIME)->requestPoolable();

    }
}

float EnemyDirector::randomizePercent(float fMax) {
    int nMax = fMax * 100;
    int nRandom = (std::rand() % nMax);
    std::cout << (float)nRandom / 100.f << std::endl;
    return (float)nRandom / 100.f;
} 

void EnemyDirector::perform() {
    this->fTicks += this->tDeltaTime.asSeconds();
    this->fUpdateTicks += this->tDeltaTime.asSeconds();
    if(this->fUpdateTicks > this->fUpdateInterval) {
        this->fUpdateTicks = 0.0f;
        this->spawnWave();
    }
}
