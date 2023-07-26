#include "Enemy.hpp"

using namespace models;

Enemy::Enemy(std::string strName, AnimatedTexture* pTexture, EnemyType EType, float fX, float fY) : GameObject(strName, pTexture, fX, fY) {
    this->EType = EType;
}

Enemy::~Enemy() {}

void Enemy::initialize() {
    this->setFrame(0);

    float fX = this->pSprite->getPosition().x;
    float fY = this->pSprite->getPosition().y;

    float fHalfWidth = this->pSprite->getTexture()->getSize().x / 2.0f;
    float fHalfHeight = this->pSprite->getTexture()->getSize().y / 2.0f;

    //this->pSprite->setOrigin(fHalfWidth, fHalfHeight);
    //this->pSprite->setPosition(fX + fHalfWidth, fY + fHalfHeight);

    Renderer* pRendererComponent = new Renderer(this->strName + " Sprite");
    pRendererComponent->assignDrawable(this->pSprite);

    this->attachComponent(pRendererComponent);
}