#include "Crosshair.hpp"

using namespace models;

Crosshair::Crosshair(std::string strName, AnimatedTexture* pTexture, float fX, float fY) : GameObject(strName, pTexture, fX, fY) {}

Crosshair::~Crosshair() {}

void Crosshair::initialize() {
    this->pSprite->setOrigin(this->pSprite->getTexture()->getSize().x / 2.0f,
                             this->pSprite->getTexture()->getSize().y / 2.0f);

    CrosshairMouseInput* pMouseInputComponent = new CrosshairMouseInput("Crosshair Mouse Input");
    
    CrosshairMovement* pMovementComponent = new CrosshairMovement("Crosshair Movement");

    Renderer* pRendererComponent = new Renderer(this->strName + " Sprite");
    pRendererComponent->assignDrawable(this->pSprite);

    this->attachComponent(pMouseInputComponent);
    this->attachComponent(pMovementComponent);
    this->attachComponent(pRendererComponent);
}
