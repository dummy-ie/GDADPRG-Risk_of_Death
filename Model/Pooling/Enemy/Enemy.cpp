#include "Enemy.hpp"

using namespace models;

Enemy::Enemy(PoolTag ETag, std::string strName, AnimatedTexture* pTexture, EnemyType EType, float fX, float fY) : PoolableObject(ETag, strName, pTexture, fX, fY) {
    this->EType = EType;
}

Enemy::~Enemy() {}

void Enemy::initialize() {
    this->setFrame(0);

    Renderer* pRendererComponent = new Renderer(this->strName + " Sprite");
    pRendererComponent->assignDrawable(this->pSprite);

    this->attachComponent(pRendererComponent);

    Killable* pKillableComponent = new Killable(this->strName + " Killable", 0.07f);
    this->attachComponent(pKillableComponent);

    PoolableKillerSystem::getInstance()->registerComponent(pKillableComponent);

    this->initializeType();
    this->randomizePosition();
}

void Enemy::randomizePosition() {
    float fX = std::rand() % SCREEN_WIDTH;
    float fY = std::rand() % SCREEN_HEIGHT;
    this->fDistance = std::rand() % (SCREEN_WIDTH / 2);

    float fWidth = this->pSprite->getTexture()->getSize().x;
    float fHeight = this->pSprite->getTexture()->getSize().y;

    float fHalfWidth = fWidth / 2.0f;
    float fHalfHeight = fHeight / 2.0f;

    if(fX < fHalfWidth)
        fX = fHalfWidth;
    else if(fX > (SCREEN_WIDTH - fHalfWidth))
        fX = (SCREEN_WIDTH - fHalfWidth);
    
    if(fY < fHalfHeight)
        fY = fHalfHeight;
    else if(fY > (SCREEN_HEIGHT - fHalfHeight))
        fY = (SCREEN_HEIGHT - fHalfHeight);
    
    float fZ = this->fDistance / SCREEN_WIDTH;
    this->pSprite->setPosition(fX, fY);
    this->pSprite->setScale(this->fSize + fZ, this->fSize + fZ);
    this->centerSpriteOrigin();
}

void Enemy::initializeType() {
    if (this->EType == EnemyType::COMMON) {
        this->nHealth = 1;
        this->fSpeed = COMMON_ENEMY_SPEED;
        this->fSize = COMMON_SPRITE_SIZE;
    }
    if (this->EType == EnemyType::UNCOMMON) {
        this->nHealth = 3;
        this->fSpeed = UNCOMMON_ENEMY_SPEED;
        this->fSize = UNCOMMON_SPRITE_SIZE;
    }
    if (this->EType == EnemyType::ELITE) {
        this->nHealth = 5;
        this->fSpeed = ELITE_ENEMY_SPEED;
        this->fSize = ELITE_SPRITE_SIZE;
    }
}

void Enemy::decrementHealth() {
    this->nHealth--;
}

void Enemy::onActivate() {
    this->setFrame(0);

    this->initializeType();
    this->randomizePosition();
    
    Movable* pMovableComponent = new Movable(this->strName + " Movable");
    this->attachComponent(pMovableComponent);
}

void Enemy::onRelease() {}

PoolableObject* Enemy::clone() {
    PoolableObject* pClone = new Enemy(this->ETag, this->strName, new AnimatedTexture(*this->pTexture), this->EType);
    return pClone;
}

int Enemy::getHealth() {
    return this->nHealth;
}

float Enemy::getSpeed() {
    return this->fSpeed;
}

float Enemy::getSize() {
    return this->fSize;
}

float Enemy::getDistance() {
    return this->fDistance;
}

void Enemy::setDistance(float fDistance) {
    this->fDistance = fDistance;
}