#include "Background.hpp"

using namespace models;

Background::Background(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {
    this->fZ = SCREEN_WIDTH;
}

Background::Background(std::string strName, AnimatedTexture* pTexture, float fZ) : GameObject(strName, pTexture) {
    this->fZ = fZ;
}

Background::~Background() {}

void Background::initialize() {
    this->setFrame(0);

    Renderer* pRendererComponent = new Renderer(this->strName + " Sprite");
    pRendererComponent->assignDrawable(this->pSprite);
    this->attachComponent(pRendererComponent);
}
