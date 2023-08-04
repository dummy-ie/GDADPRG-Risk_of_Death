#include "TriangleHitbox.hpp"

using namespace models;

TriangleHitbox::TriangleHitbox(std::string strName) : Hitbox(strName) {}

TriangleHitbox::~TriangleHitbox() {}

void TriangleHitbox::initialize() {
    float fWidth = this->getParent()->getSprite()->getTexture()->getSize().x;

    float fHalfWidth = fWidth / 2.0f;

    float fX = this->getParent()->getSprite()->getPosition().x;
    float fY = this->getParent()->getSprite()->getPosition().y; 

    this->CColor = sf::Color::Red;
    this->CColor.a = 100;

    float fRadius = fHalfWidth * this->getParent()->getSprite()->getScale().x;

    this->pShape = new sf::CircleShape(fRadius, 3);

    this->pShape->setFillColor(this->CColor);
    this->pShape->setPosition(fX, fY);
    this->pShape->setOrigin(fRadius, fRadius);
}

bool TriangleHitbox::contains(sf::Vector2f vecLocation) {
    sf::Vector2f vecCenter = this->pShape->getPosition();
    float fRadius = ((sf::CircleShape*)this->pShape)->getRadius();

    sf::Vector2f vecPoint1 = sf::Vector2f(vecCenter.x, vecCenter.y + fRadius);
    sf::Vector2f vecPoint2 = sf::Vector2f(vecCenter.x - fRadius, vecCenter.y - fRadius);
    sf::Vector2f vecPoint3 = sf::Vector2f(vecCenter.x + fRadius, vecCenter.y - fRadius);

    float fTriangleArea = calculateDeterminant(vecPoint1, vecPoint2, vecPoint3);
    float fArea1 = calculateDeterminant(vecLocation, vecPoint2, vecPoint3);
    float fArea2 = calculateDeterminant(vecLocation, vecPoint1, vecPoint3);
    float fArea3 = calculateDeterminant(vecLocation, vecPoint1, vecPoint2);

    if ((fArea1 + fArea2 + fArea3) <= fTriangleArea) {
        return true;
    }
    return false;
}

void TriangleHitbox::move(sf::Time tDeltaTime) {
    float fX = this->getParent()->getSprite()->getPosition().x;
    float fY = this->getParent()->getSprite()->getPosition().y;
    float fWidth = this->getParent()->getSprite()->getTexture()->getSize().x;
    float fHalfWidth = fWidth / 2.0f;
    float fRadius = fHalfWidth * this->getParent()->getSprite()->getScale().x;

    this->pShape->setPosition(sf::Vector2f(fX, fY));
    this->pShape->setOrigin(fRadius, fRadius);
    ((sf::CircleShape*)this->pShape)->setRadius(fRadius);
}

float TriangleHitbox::calculateDeterminant(sf::Vector2f vecPoint1, sf::Vector2f vecPoint2, sf::Vector2f vecPoint3) {
    float fDet = ((vecPoint1.x - vecPoint3.x) * (vecPoint2.y - vecPoint3.y)) - ((vecPoint2.x - vecPoint3.x) * (vecPoint1.y - vecPoint3.y));
    return fDet / 2.0f;
}