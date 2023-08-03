#include "Enemy.hpp"

using namespace models;

Enemy::Enemy(PoolTag ETag, std::string strName, AnimatedTexture* pTexture, EnemyType EType) : PoolableObject(ETag, strName, pTexture) {
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

    this->pRectangle = new sf::RectangleShape(sf::Vector2f(50, this->pSprite->getTexture()->getSize().y));
    pRendererComponent = new Renderer(this->strName + " Rectangle");
    pRendererComponent->assignDrawable(this->pRectangle);
    this->pRectangle->setPosition(sf::Vector2f(this->fZ, this->pSprite->getPosition().y));
    this->attachComponent(pRendererComponent);

    this->pRectangle->setFillColor(this->CColor);
    int nHeight = this->pSprite->getTexture()->getSize().y;

    float fHalfWidth = 50 / 2.0f;
    float fHalfHeight = nHeight / 2.0f;
    this->pRectangle->setOrigin(fHalfWidth, fHalfHeight);
}

void Enemy::randomizePosition() {
    float fX = std::rand() % SCREEN_WIDTH;
    float fY = std::rand() % SCREEN_HEIGHT;
    this->fZ = (3 * SCREEN_WIDTH / 4) + std::rand() % (SCREEN_WIDTH / 4);

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
    
    float fZ = (SCREEN_WIDTH - this->fZ) / SCREEN_WIDTH;
    this->pSprite->setPosition(fX, fY);
    //this->fBottom = this->pSprite->getGlobalBounds().top - this->pSprite->getGlobalBounds().height;
    this->pSprite->setScale(this->fSize + fZ, this->fSize + fZ);
    this->centerSpriteOrigin();
}

void Enemy::initializeType() {
    if (this->EType == EnemyType::COMMON) {
        this->nHealth = 1;
        this->CColor = sf::Color::Green;
        this->fSpeed = COMMON_ENEMY_SPEED;
        this->fSize = COMMON_SPRITE_SIZE;
    }
    if (this->EType == EnemyType::UNCOMMON) {
        this->nHealth = 3;
        this->CColor = sf::Color::Magenta;
        this->fSpeed = UNCOMMON_ENEMY_SPEED;
        this->fSize = UNCOMMON_SPRITE_SIZE;
    }
    if (this->EType == EnemyType::ELITE) {
        this->nHealth = 5;
        this->CColor = sf::Color::Red;
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
    
    this->pMover = new Mover(this->strName + " Mover");
    this->pMover->setMovable(this);

    this->attachComponent(this->pMover); 
}

void Enemy::onRelease() {}

PoolableObject* Enemy::clone() {
    PoolableObject* pClone = new Enemy(this->ETag, this->strName, new AnimatedTexture(*this->pTexture), this->EType);
    return pClone;
}

void Enemy::move(sf::Time tDeltaTime) {
    float fMovement = this->fSpeed * tDeltaTime.asSeconds();
    this->fZ = this->fZ - fMovement;
    float fZ = (SCREEN_WIDTH - this->fZ) / SCREEN_WIDTH;
    this->getSprite()->setScale(this->fSize + fZ, this->fSize + fZ);
    this->pRectangle->setPosition(this->fZ, this->pRectangle->getPosition().y);
}

int Enemy::getHealth() {
    return this->nHealth;
}

float Enemy::getSize() {
    return this->fSize;
}