#include "ParallaxBackground.hpp"

using namespace models;

ParallaxBackground::ParallaxBackground(std::string strName) : GameObject(strName) {}

ParallaxBackground::~ParallaxBackground() {}

void ParallaxBackground::addLayer(AnimatedTexture *pTexture, float fDistance) {
    this->attachChild(new Background(this->strName + " Layer Background " + this->vecChildren.size(), pTexture, fDistance));
}