#include "Enemy.hpp"

using namespace models;

Enemy::Enemy(PoolTag ETag, std::string strName, AnimatedTexture *pTexture, EnemyType EType, HitboxType EHitbox) : PoolableObject(ETag, strName, pTexture)
{
    this->EType = EType;
    this->EHitbox = EHitbox;
}

Enemy::~Enemy() {}

void Enemy::initialize()
{
    this->setFrame(0);

    this->pRectangle = new sf::RectangleShape(sf::Vector2f(50, this->pSprite->getTexture()->getSize().y));

    this->pSpriteRenderer = new Renderer(this->strName + " Sprite");
    this->pSpriteRenderer->assignDrawable(this->pSprite);

    this->attachComponent(this->pSpriteRenderer);

    Killable *pKillableComponent = new Killable(this->strName + " Killable", 0.07f);
    this->attachComponent(pKillableComponent);

    PoolableKillerSystem::getInstance()->registerComponent(pKillableComponent);

    this->initializeType();
    this->randomizePosition();

    this->pRectangle->setSize(sf::Vector2f(this->pRectangle->getSize().x, this->pRectangle->getSize().y * this->fSize));

    this->pRectangleRenderer = new Renderer(this->strName + " Rectangle");
    this->pRectangleRenderer->assignDrawable(this->pRectangle);
    this->attachComponent(this->pRectangleRenderer);
    this->pRectangle->setFillColor(this->CColor);

    this->pSwitcher = new Switcher(this->strName + " Switcher");
    this->attachComponent(this->pSwitcher);
    this->pSwitcher->setSwitchable(this);

    if (EHitbox == HitboxType::CIRCLE)
        this->pHitbox = new CircleHitbox(this->strName + " Hitbox");
    if (EHitbox == HitboxType::RECTANGLE)
        this->pHitbox = new RectangleHitbox(this->strName + " Hitbox");
    if (EHitbox == HitboxType::TRIANGLE)
        this->pHitbox = new TriangleHitbox(this->strName + " Hitbox");

    this->attachChild(this->pHitbox);
    
    this->pMover = new Mover(this->strName + " Mover");
    this->pMover->setMovable(this);
    this->attachComponent(this->pMover); 
    
    this->pHitboxRenderer = new Renderer(this->strName + " Hitbox");
    this->pHitboxRenderer->assignDrawable(this->pHitbox->getShape());
    this->attachComponent(this->pHitboxRenderer);
    if (!RENDER_HITBOX)
        this->pHitboxRenderer->disable();
}

void Enemy::randomizePosition()
{
    float fX = std::rand() % SCREEN_WIDTH;
    float fY = std::rand() % SCREEN_HEIGHT;
    this->fZ = SCREEN_WIDTH;

    float fWidth = this->pSprite->getTexture()->getSize().x;
    float fHeight = this->pSprite->getTexture()->getSize().y;

    float fHalfWidth = fWidth / 2.0f;
    float fHalfHeight = fHeight / 2.0f;

    if (fX < fHalfWidth)
        fX = fHalfWidth;
    else if (fX > (SCREEN_WIDTH - fHalfWidth))
        fX = (SCREEN_WIDTH - fHalfWidth);

    if (fY < fHalfHeight)
        fY = fHalfHeight;
    else if (fY > (SCREEN_HEIGHT - fHalfHeight))
        fY = (SCREEN_HEIGHT - fHalfHeight);

    float fZ = (SCREEN_WIDTH - this->fZ) / SCREEN_WIDTH;
    this->pSprite->setPosition(fX, fY);
    // this->fBottom = this->pSprite->getGlobalBounds().top - this->pSprite->getGlobalBounds().height;
    this->pSprite->setScale(this->fSize + fZ, this->fSize + fZ);

    //if (WindowManager::getInstance()->getWindow()->getView().getSize() == WindowManager::getInstance()->getWindow()->getDefaultView().getSize())
    //    this->getSprite()->scale(sf::Vector2f(1.f / (float)WindowManager::getInstance()->getPartitions()->size(), 1.f / (float)WindowManager::getInstance()->getPartitions()->size()));
    //else
    //    this->getSprite()->scale(sf::Vector2f(0.5f, 0.5f));
    
    this->centerSpriteOrigin();
    
    this->pRectangle->setPosition(sf::Vector2f(this->fZ, fY));
    int nHeight = this->pSprite->getTexture()->getSize().y;
    fHalfWidth = 50 / 2.0f;
    fHalfHeight = nHeight / 2.0f;
    this->pRectangle->setOrigin(fHalfWidth, fHalfHeight);

}

void Enemy::initializeType()
{
    if (this->EType == EnemyType::COMMON)
    {
        this->nHealth = 1;
        this->CColor = sf::Color::Green;
        this->fSpeed = MIN_COMMON_ENEMY_SPEED + ((float)(std::rand() % ((int)MAX_COMMON_ENEMY_SPEED * 100)) / 100.f);
        this->fSize = COMMON_SPRITE_SIZE;
    }
    if (this->EType == EnemyType::UNCOMMON)
    {
        this->nHealth = 3;
        this->CColor = sf::Color::Magenta;
        this->fSpeed = MIN_UNCOMMON_ENEMY_SPEED + ((float)(std::rand() % ((int)MAX_UNCOMMON_ENEMY_SPEED * 100)) / 100.f);;
        this->fSize = UNCOMMON_SPRITE_SIZE;
    }
    if (this->EType == EnemyType::ELITE)
    {
        this->nHealth = 5;
        this->CColor = sf::Color::Red;
        this->fSpeed = MIN_ELITE_ENEMY_SPEED + ((float)(std::rand() % ((int)MAX_ELITE_ENEMY_SPEED * 100)) / 100.f);;
        this->fSize = ELITE_SPRITE_SIZE;
    }
}

void Enemy::decrementHealth()
{
    if (PowerUpSystem::getInstance()->isActive(ItemType::PWR_DAMAGE))
    {
        this->nHealth--;
    }
    this->nHealth--;
}

void Enemy::onActivate()
{
    this->setFrame(0);

    this->randomizePosition();
    this->initializeType();

    
    

    
    ViewSwitcherSystem::getInstance()->registerComponent(this->pSwitcher);
}

void Enemy::onRelease() {

    ViewSwitcherSystem::getInstance()->unregisterComponent(this->pSwitcher);
}

PoolableObject *Enemy::clone()
{
    PoolableObject *pClone = new Enemy(this->ETag, this->strName, new AnimatedTexture(*this->pTexture), this->EType, this->EHitbox);
    return pClone;
}

void Enemy::move(float fTicks, sf::Time tDeltaTime)
{   
    float fMovement = this->fSpeed * fTicks * tDeltaTime.asSeconds();
    this->fZ = this->fZ - fMovement;
    float fZ = (SCREEN_WIDTH - this->fZ) / SCREEN_WIDTH;
    this->getSprite()->setScale(this->fSize + fZ, this->fSize + fZ);
    this->pRectangle->setPosition(this->fZ, this->pRectangle->getPosition().y);
    this->pHitbox->move(0.0f, tDeltaTime);

    //if (WindowManager::getInstance()->getWindow()->getView().getSize() == WindowManager::getInstance()->getWindow()->getDefaultView().getSize())
    //    this->getSprite()->scale(sf::Vector2f(1.f / (float)WindowManager::getInstance()->getPartitions()->size(), 1.f / (float)WindowManager::getInstance()->getPartitions()->size()));
}

bool Enemy::contains(sf::Vector2f vecLocation) {
    return this->pHitbox->contains(vecLocation);
}

void Enemy::switchLeftView() {
    this->pSpriteRenderer->disable();
    this->pRectangleRenderer->enable();
}

void Enemy::switchFrontView() {
    this->pSpriteRenderer->enable();
    this->pRectangleRenderer->disable();
}

int Enemy::getHealth() {
    return this->nHealth;
}

float Enemy::getSize()
{
    return this->fSize;
}
EnemyType Enemy::getType(){
    return this->EType;
}