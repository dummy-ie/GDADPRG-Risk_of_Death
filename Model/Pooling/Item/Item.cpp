#include "Item.hpp"

using namespace models;

Item::Item(PoolTag ETag, std::string strName, AnimatedTexture* pTexture, ItemType EType, float fX, float fY) : PoolableObject(ETag, strName, pTexture, fX, fY) {
    this->EType = EType;
}

Item::~Item() {}

void Item::initialize() {
    this->setFrame(0);

    this->pSpriteRenderer = new Renderer(this->strName + " Sprite");
    this->pSpriteRenderer->assignDrawable(this->pSprite);

    this->attachComponent(this->pSpriteRenderer);

    if(this->EType == ItemType::NONE){
        this->randomizeType();
    }

    this->pCollectable = new Collectable(this->strName + " Collectable");
    this->attachComponent(this->pCollectable);

    ItemCollectorSystem::getInstance()->registerComponent(this->pCollectable);

    this->pSwitcher = new Switcher(this->strName + " Switcher");
    this->attachComponent(this->pSwitcher);
    this->pSwitcher->setSwitchable(this);
    
    this->getSprite()->setScale(0.2,0.2);

    this->centerSpriteOrigin();

    this->pHitbox = new RectangleHitbox(this->strName + " Hitbox");
    this->attachChild(this->pHitbox);

    Renderer* pHitboxRenderer = new Renderer(this->strName + " Hitbox Renderer");
    pHitboxRenderer->assignDrawable(this->pHitbox->getShape());
    this->attachComponent(pHitboxRenderer);

    if (!RENDER_HITBOX)
        pHitboxRenderer->disable();

}

void Item::collect(){
    switch(this->EType){
        case ItemType::PWR_HEALTH: case ItemType::PWR_INVINCIBILITY:
            ItemManager::getInstance()->addItem(this->EType, true);
            break;
        default:
            ItemManager::getInstance()->addItem(this->EType);
            break;
    }
    SFXManager::getInstance()->getSound(SFXType::HEALTH)->play();
    GameSpaceUI* pGameSpaceUI = (GameSpaceUI*)GameObjectManager::getInstance()->findObjectByName("Game Space UI");
    pGameSpaceUI->update();
    //ObjectPoolManager::getInstance()->getPool(this->ETag)->releasePoolable(this);
}

bool Item::contains(sf::Vector2f vecLocation) {
    return this->pHitbox->contains(vecLocation);
}

void Item::switchLeftView(){
    this->pSpriteRenderer->disable();
}
void Item::switchFrontView(){
    this->pSpriteRenderer->enable();
}

void Item::randomizeType(){
    this->EType = (ItemType)(std::rand() % 5);
    this->setFrame((int)EType);

    EmptyGameObject* pSpawnPoint = (EmptyGameObject*)GameObjectManager::getInstance()->findObjectByName("Item Spawn Location");
    if(pSpawnPoint){
        this->setPosition(pSpawnPoint->getPosition());
        this->pHitbox->move(0.0f, this->pCollectable->getDeltaTime());
    }
}

void Item::onActivate() {
    SFXManager::getInstance()->getSound(SFXType::SHINY)->play();
    this->randomizeType();
    this->pCollectable->startTimer();
    ViewSwitcherSystem::getInstance()->registerComponent(this->pSwitcher);
}

void Item::onRelease() {
    ViewSwitcherSystem::getInstance()->unregisterComponent(this->pSwitcher);
}

PoolableObject* Item::clone() {
    PoolableObject* pClone = new Item(this->ETag, this->strName, new AnimatedTexture(*this->pTexture), this->EType);
    return pClone;
}