#include "Hitbox.hpp"

using namespace models;

Hitbox::Hitbox(std::string strName) : GameObject(strName) {}

Hitbox::~Hitbox() {}

sf::Shape* Hitbox::getShape() {
    return this->pShape;
}

void Hitbox::setOffset(float fX, float fY) {
    this->COffset = sf::FloatRect(0.0f, 0.0f, fX, fY);
}