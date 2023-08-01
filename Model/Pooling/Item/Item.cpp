#include "Item.hpp"

using namespace models;

Item::Item(PoolTag ETag, std::string strName, AnimatedTexture* pTexture, ItemType EType, float fX, float fY) : PoolableObject(ETag, strName, pTexture, fX, fY) {
    this->EType = EType;
}

Item::~Item() {}

void Item::initialize() {
    this->setFrame(0);

    Renderer* pRendererComponent = new Renderer(this->strName + " Sprite");
    pRendererComponent->assignDrawable(this->pSprite);

    this->attachComponent(pRendererComponent);

    if(this->EType == ItemType::NONE){
        this->randomizeType();
    }

    Collectable* pCollectableComponent = new Collectable(this->strName + " Collectable");
    this->attachComponent(pCollectableComponent);

    ItemCollectorSystem::getInstance()->registerComponent(pCollectableComponent);
    //this->randomizePosition();
}

void Item::collect(){
    ObjectPoolManager::getInstance()->getPool(this->ETag)->releasePoolable(this);
}

void Item::randomizeType(){
    this->EType = (ItemType)(std::rand() % 5);
}

/*
void Item::randomizePosition() {
    float fX = std::rand() % SCREEN_WIDTH;
    float fY = std::rand() % SCREEN_HEIGHT;
    float fZ = std::rand() % 10 / 1.0f;

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
        
    this->pSprite->setPosition(fX, fY);
    this->pSprite->setScale(fZ, fZ);
    this->centerSpriteOrigin();
}
*/

void Item::onActivate() {}

void Item::onRelease() {
    ItemManager::getInstance()->addItem(this->EType);
}

PoolableObject* Item::clone() {
    PoolableObject* pClone = new Item(this->ETag, this->strName, new AnimatedTexture(*this->pTexture), this->EType);
    return pClone;
}