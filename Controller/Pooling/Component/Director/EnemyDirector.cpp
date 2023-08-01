#include "EnemyDirector.hpp"

using namespace directors;

EnemyDirector::EnemyDirector(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fSpawnInterval = 1.0f;
    this->fTicks = 0.0f;

    this->createEnemyPool(PoolTag::GREEN_SLIME, 3, EnemyType::COMMON, AssetType::GREEN_SLIME);
    this->createEnemyPool(PoolTag::PURPLE_SLIME, 3, EnemyType::UNCOMMON, AssetType::PURPLE_SLIME);
    //this->createEnemyPool(PoolTag::YELLOW_SLIME, 3, EnemyType::COMMON, AssetType::YELLOW_SLIME);
    this->createEnemyPool(PoolTag::RED_SLIME, 3, EnemyType::ELITE, AssetType::RED_SLIME);
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

void EnemyDirector::randomizedSpawn() {
    int nRandom = rand() % 3;
    switch (nRandom) {
        case 0:
            ObjectPoolManager::getInstance()->getPool(PoolTag::GREEN_SLIME)->requestPoolable();
            break;
        case 1:
            ObjectPoolManager::getInstance()->getPool(PoolTag::PURPLE_SLIME)->requestPoolable();
            break;
        case 2:
            ObjectPoolManager::getInstance()->getPool(PoolTag::RED_SLIME)->requestPoolable();
            break;
        /*    ObjectPoolManager::getInstance()->getPool(PoolTag::YELLOW_SLIME)->requestPoolable();
        case 3:
            break;
        case 4:
            ObjectPoolManager::getInstance()->getPool(PoolTag::BLUE_SLIME)->requestPoolable();
            break;*/
    }
}

void EnemyDirector::perform() {
    this->fTicks += this->tDeltaTime.asSeconds();

    if(this->fTicks > this->fSpawnInterval) {
        this->fTicks = 0.0f;
        this->randomizedSpawn();
    }
}
