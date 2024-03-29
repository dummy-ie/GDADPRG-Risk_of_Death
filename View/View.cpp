#include "View.hpp"

using namespace views;

View::View(ViewTag ETag, std::string strName) : GameObject(strName) {
    this->ETag = ETag;
}

View::~View() {}

void View::createImage(std::string strName, AnimatedTexture* pTexture, float fScale, float fX, float fY, float fZ) {
    Image* pImage = new Image(strName, pTexture);
    pImage->getSprite()->setScale(fScale, fScale);
    pImage->setPosition(fX, fY, fZ);

    this->attachChild(pImage);
}

ViewTag View::getTag() {
    return this->ETag;
}