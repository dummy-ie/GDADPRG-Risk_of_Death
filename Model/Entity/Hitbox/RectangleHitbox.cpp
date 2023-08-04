#include "RectangleHitbox.hpp"

using namespace models;

RectangleHitbox::RectangleHitbox(std::string strName) : Hitbox(strName) {}

RectangleHitbox::~RectangleHitbox() {}

void RectangleHitbox::initialize() {
    float fWidth = this->getParent()->getSprite()->getTexture()->getSize().x;
    float fHeight = this->getParent()->getSprite()->getTexture()->getSize().y;

    float fHalfWidth = fWidth / 2.0f;
    float fhalfHeight = fHeight / 2.0f;

    float fX = this->getParent()->getSprite()->getPosition().x;
    float fY = this->getParent()->getSprite()->getPosition().y; 

    this->CColor = sf::Color::Red;
    this->CColor.a = 100;

    this->pShape = new sf::RectangleShape(sf::Vector2f(fWidth * this->getParent()->getSprite()->getScale().x, fHeight * this->getParent()->getSprite()->getScale().y));

    this->pShape->setFillColor(this->CColor);
    this->pShape->setPosition(fX, fY);
    this->pShape->setOrigin((fWidth * this->getParent()->getSprite()->getScale().x) / 2, (fHeight * this->getParent()->getSprite()->getScale().y) / 2);
}

bool RectangleHitbox::contains(sf::Vector2f vecLocation) {
    sf::Vector2f vecCenter = this->pShape->getPosition();
    float fWidth = ((sf::RectangleShape*)this->pShape)->getSize().x;
    float fHeight = ((sf::RectangleShape*)this->pShape)->getSize().y;
    sf::FloatRect CBounds = sf::FloatRect(vecCenter.x - fWidth / 2, vecCenter.y - fHeight / 2, fWidth, fHeight);
    return CBounds.contains(vecLocation);
}

void RectangleHitbox::move(float fTicks, sf::Time tDeltaTime) {
    float fX = this->getParent()->getSprite()->getPosition().x + this->COffset.width;
    float fY = this->getParent()->getSprite()->getPosition().y + this->COffset.height;
    float fWidth = this->getParent()->getSprite()->getTexture()->getSize().x;
    float fHeight = this->getParent()->getSprite()->getTexture()->getSize().y;

    fWidth *= this->getParent()->getSprite()->getScale().x;
    fHeight *= this->getParent()->getSprite()->getScale().y;

    float fHalfWidth = fWidth / 2.0f;
    float fHalfHeight = fHeight / 2.0f;

    this->pShape->setPosition(sf::Vector2f(fX, fY));
    this->pShape->setOrigin(fHalfWidth, fHalfHeight);
    ((sf::RectangleShape*)this->pShape)->setSize(sf::Vector2f(fWidth, fHeight));
}