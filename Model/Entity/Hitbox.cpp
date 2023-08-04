#include "Hitbox.hpp"

using namespace models;

Hitbox::Hitbox(std::string strName) : GameObject(strName) {}

Hitbox::~Hitbox() {}

sf::Shape* Hitbox::getShape() {
    return this->pShape;
}