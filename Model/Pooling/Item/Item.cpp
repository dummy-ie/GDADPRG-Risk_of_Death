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
    
    this->getSprite()->setScale(0.2,0.2);

    this->centerSpriteOrigin();

    this->pHitbox = new RectangleHitbox(this->strName + " Hitbox");
    this->attachChild(this->pHitbox);

    Renderer* pHitboxRenderer = new Renderer(this->strName + " Hitbox Renderer");
    pHitboxRenderer->assignDrawable(this->pHitbox->getShape());
    this->attachComponent(pHitboxRenderer);

}

void Item::collect(){
    ObjectPoolManager::getInstance()->getPool(this->ETag)->releasePoolable(this);
}

bool Item::contains(sf::Vector2f vecLocation) {
    return this->pHitbox->contains(vecLocation);
}

void Item::randomizeType(){
    this->EType = (ItemType)(std::rand() % 5);
    this->setFrame((int)EType);

    EmptyGameObject* pSpawnPoint = (EmptyGameObject*)GameObjectManager::getInstance()->findObjectByName("Item Spawn Location");
    if(pSpawnPoint){
        this->setPosition(pSpawnPoint->getPosition());
    }
}

void Item::onActivate() {
    this->randomizeType();
}

void Item::onRelease() {
    ItemManager::getInstance()->addItem(this->EType);
}

PoolableObject* Item::clone() {
    PoolableObject* pClone = new Item(this->ETag, this->strName, new AnimatedTexture(*this->pTexture), this->EType);
    return pClone;
}