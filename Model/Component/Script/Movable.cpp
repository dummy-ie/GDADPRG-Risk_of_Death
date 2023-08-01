#include "Movable.hpp"

using namespace components;

Movable::Movable(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    float fTicks = 0.0f;
}

void Movable::perform() {

}