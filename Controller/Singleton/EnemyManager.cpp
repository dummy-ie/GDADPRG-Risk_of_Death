#include "EnemyManager.hpp"

using namespace controllers;

void EnemyManager::loadAll() {
    this->create(PoolTag::GREEN_SLIME, "Green Slime", AssetType::GREEN_SLIME, EnemyType::COMMON, HitboxType::CIRCLE);
    this->create(PoolTag::PURPLE_SLIME, "Purple Slime", AssetType::PURPLE_SLIME, EnemyType::UNCOMMON, HitboxType::CIRCLE);
    this->create(PoolTag::RED_SLIME, "Red Slime", AssetType::RED_SLIME, EnemyType::ELITE, HitboxType::CIRCLE);
}

void EnemyManager::create(PoolTag ETag, std::string strName, AssetType ETexture, EnemyType EType, HitboxType EHitbox) {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(ETexture));
    Enemy* pEnemy = new Enemy(ETag, strName, pTexture, EType, EHitbox);
    this->mapEnemyType[EType].push_back(pEnemy);
}

void EnemyManager::addEnemy(Enemy* pEnemy) {
    this->vecEnemies.push_back(pEnemy);
}

std::vector<Enemy*> EnemyManager::getEnemies() {
    return this->vecEnemies;
}

std::vector<Enemy*> EnemyManager::getAllType(EnemyType EType) {
    return this->mapEnemyType[EType];
}

EnemyManager* EnemyManager::P_SHARED_INSTANCE = NULL;
EnemyManager::EnemyManager() {}
EnemyManager::EnemyManager(const EnemyManager&) {}

EnemyManager* EnemyManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new EnemyManager();

    return P_SHARED_INSTANCE;
}