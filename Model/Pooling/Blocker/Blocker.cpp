#include "Blocker.hpp"

using namespace models;

Blocker::Blocker(PoolTag ETag, std::string strName, AnimatedTexture *pTexture, BlockerType EType, HitboxType EHitbox) : PoolableObject(ETag, strName, pTexture)
{
    this->EType = EType;
    this->EHitbox = EHitbox;
    this->fSpeed = BLOCKER_SPEED;
}

Blocker::~Blocker() {}

void Blocker::initialize()
{
    this->setFrame(0);

    this->pSpriteRenderer = new Renderer(this->strName + " Sprite");
    this->pSpriteRenderer->assignDrawable(this->pSprite);

    this->attachComponent(this->pSpriteRenderer);

    BlockerManager::getInstance()->addBlocker(this);

    this->pDirectionSwap = new DirectionSwap(this->strName + " Direction Swap");
    this->attachComponent(this->pDirectionSwap);

    this->getSprite()->setScale(BLOCKER_SPRITE_SIZE,BLOCKER_SPRITE_SIZE);

    if (EHitbox == HitboxType::CIRCLE)
        this->pHitbox = new CircleHitbox(this->strName + " Hitbox");
    if (EHitbox == HitboxType::RECTANGLE)
        this->pHitbox = new RectangleHitbox(this->strName + " Hitbox");
    if (EHitbox == HitboxType::TRIANGLE)
        this->pHitbox = new TriangleHitbox(this->strName + " Hitbox");
        this->pHitbox->setOffset(5.f,20.f);

    this->attachChild(this->pHitbox);
    
    this->CColor = sf::Color::Cyan;

    this->pRectangle = new sf::RectangleShape(sf::Vector2f(50, this->pSprite->getTexture()->getSize().y));
    pRectangle->setTexture(this->pSprite->getTexture());

    this->pRectangleRenderer = new Renderer(this->strName + " Rectangle");
    this->pRectangleRenderer->assignDrawable(this->pRectangle);
    this->attachComponent(this->pRectangleRenderer);
    if (SIDE_VIEW_SPRITE_TINT)
        this->pRectangle->setFillColor(this->CColor);

    this->pSwitcher = new Switcher(this->strName + " Switcher");
    this->attachComponent(this->pSwitcher);
    this->pSwitcher->setSwitchable(this);

    this->pMover = new Mover(this->strName + " Mover");
    this->pMover->setMovable(this);

    this->attachComponent(this->pMover); 
    
    this->pHitboxRenderer = new Renderer(this->strName + " Hitbox");
    this->pHitboxRenderer->assignDrawable(this->pHitbox->getShape());
    this->attachComponent(this->pHitboxRenderer);
    if (!RENDER_HITBOX)
        this->pHitboxRenderer->disable();

    ViewSwitcherSystem::getInstance()->registerComponent(this->pSwitcher);
}

void Blocker::randomizePosition()
{
    float fX = std::rand() % SCREEN_WIDTH;
    float fY = std::rand() % SCREEN_HEIGHT;

    float fWidth = this->pSprite->getTexture()->getSize().x;
    float fHeight = this->pSprite->getTexture()->getSize().y;
    this->fZ = 0.f;

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

    this->pSprite->setPosition(fX, fY);
    // this->fBottom = this->pSprite->getGlobalBounds().top - this->pSprite->getGlobalBounds().height;

    //if (WindowManager::getInstance()->getWindow()->getView().getSize() == WindowManager::getInstance()->getWindow()->getDefaultView().getSize())
    //    this->getSprite()->scale(sf::Vector2f(1.f / (float)WindowManager::getInstance()->getPartitions()->size(), 1.f / (float)WindowManager::getInstance()->getPartitions()->size()));
    //else
    //    this->getSprite()->scale(sf::Vector2f(0.5f, 0.5f));

    this->centerSpriteOrigin();

}


void Blocker::onActivate()
{
    this->randomizePosition();
}

void Blocker::onRelease() {
    this->detachComponent(this->pMover);
    delete this->pMover;
}

PoolableObject *Blocker::clone()
{
    PoolableObject *pClone = new Blocker(this->ETag, this->strName, new AnimatedTexture(*this->pTexture), this->EType, this->EHitbox);
    return pClone;
}

void Blocker::move(float fTicks, sf::Time tDeltaTime)
{
    float fMovement = this->fSpeed * tDeltaTime.asSeconds();
    switch(this->EType){
        case BlockerType::LEFTRIGHT:
            if(this->pDirectionSwap->getDirection()){
                this->setPosition(this->getPosition().x - fMovement,this->getPosition().y, this->fZ);
            }
            else{
                this->setPosition(this->getPosition().x + fMovement,this->getPosition().y, this->fZ);
            }
            break;
        case BlockerType::UPDOWN:
            if(this->pDirectionSwap->getDirection()){
                this->setPosition(this->getPosition().x, this->getPosition().y - fMovement, this->fZ);
            }
            else{
                this->setPosition(this->getPosition().x,this->getPosition().y + fMovement, this->fZ);
            }
            break;
        default:
            break;
    }
    this->pHitbox->move(0.0f, tDeltaTime);
    this->pRectangle->setPosition(this->fZ, this->getPosition().y);
}

bool Blocker::contains(sf::Vector2f vecLocation) {
    return this->pHitbox->contains(vecLocation);
}

void Blocker::switchLeftView() {
    this->pSpriteRenderer->disable();
    this->pRectangleRenderer->enable();
}

void Blocker::switchFrontView() {
    this->pSpriteRenderer->enable();
    this->pRectangleRenderer->disable();
}