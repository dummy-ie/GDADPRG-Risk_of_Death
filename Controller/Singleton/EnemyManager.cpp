#include "EnemyManager.hpp"

using namespace controllers;

void EnemyManager::loadAll() {
    this->create(PoolTag::GREEN_SLIME, "Green Slime", AssetType::GREEN_SLIME, EnemyType::COMMON, HitboxType::CIRCLE);
    this->create(PoolTag::PURPLE_SLIME, "Purple Slime", AssetType::PURPLE_SLIME, EnemyType::UNCOMMON, HitboxType::CIRCLE);
    this->create(PoolTag::RED_SLIME, "Red Slime", AssetType::RED_SLIME, EnemyType::ELITE, HitboxType::CIRCLE);

    this->create(PoolTag::COMMON_LAND, "Spiky Monster", AssetType::COMMON_LAND, EnemyType::COMMON, HitboxType::TRIANGLE);
    this->create(PoolTag::UNCOMMON_LAND, "Walky Monster", AssetType::UNCOMMON_LAND, EnemyType::UNCOMMON, HitboxType::RECTANGLE);
    this->create(PoolTag::ELITE_LAND, "Chompy Monster", AssetType::ELITE_LAND, EnemyType::ELITE, HitboxType::RECTANGLE);

    this->create(PoolTag::COMMON_INSECT, "Black Spider", AssetType::COMMON_INSECT, EnemyType::COMMON, HitboxType::CIRCLE);
    this->create(PoolTag::UNCOMMON_INSECT, "Orange Spider", AssetType::UNCOMMON_INSECT, EnemyType::UNCOMMON, HitboxType::CIRCLE);
    this->create(PoolTag::ELITE_INSECT, "Yellow Bee", AssetType::ELITE_INSECT, EnemyType::ELITE, HitboxType::CIRCLE);
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

void EnemyManager::clearAll(){
    this->mapEnemyType.clear();
    this->vecEnemies.clear();
}

EnemyManager* EnemyManager::P_SHARED_INSTANCE = NULL;
EnemyManager::EnemyManager() {}
EnemyManager::EnemyManager(const EnemyManager&) {}

EnemyManager* EnemyManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new EnemyManager();

    return P_SHARED_INSTANCE;
}