#include "CircleHitbox.hpp"

using namespace models;

CircleHitbox::CircleHitbox(std::string strName) : Hitbox(strName) {}

CircleHitbox::~CircleHitbox() {}

void CircleHitbox::initialize() {

    float fWidth = this->getParent()->getSprite()->getTexture()->getSize().x;

    float fHalfWidth = fWidth / 2.0f;

    float fX = this->getParent()->getSprite()->getPosition().x;
    float fY = this->getParent()->getSprite()->getPosition().y; 

    this->CColor = sf::Color::Red;
    this->CColor.a = 100;

    float fRadius = fHalfWidth * this->getParent()->getSprite()->getScale().x;

    this->pShape = new sf::CircleShape(fRadius);

    this->pShape->setFillColor(this->CColor);
    this->pShape->setPosition(fX, fY);
    this->pShape->setOrigin(fRadius, fRadius);
}

bool CircleHitbox::contains(sf::Vector2f vecLocation) {
    sf::Vector2f vecCenter = this->pShape->getPosition();
    float fRadius = ((sf::CircleShape*)this->pShape)->getRadius();
    float fDistance = sqrt(pow(vecLocation.x - vecCenter.x, 2) + pow(vecLocation.y - vecCenter.y, 2));
    if (fDistance <= fRadius) {
        return true;
    }
    return false;
}

void CircleHitbox::move(sf::Time tDeltaTime) {
    float fX = this->getParent()->getSprite()->getPosition().x;
    float fY = this->getParent()->getSprite()->getPosition().y;
    float fWidth = this->getParent()->getSprite()->getTexture()->getSize().x;
    float fHalfWidth = fWidth / 2.0f;
    float fRadius = fHalfWidth * this->getParent()->getSprite()->getScale().x;

    this->pShape->setPosition(sf::Vector2f(fX, fY));
    this->pShape->setOrigin(fRadius, fRadius);
    ((sf::CircleShape*)this->pShape)->setRadius(fRadius);
}