#include "PlayerInput.hpp"

using namespace components;

PlayerInput::PlayerInput(std::string strName) : GeneralInput(strName) {
    this->bLeft = false;
    this->bRight = false;
    this->b1 = false;
    this->b2 = false;
    this->b3 = false;
    this->bPartition = false;
    this->bZoomOut = false;
}

void PlayerInput::perform() {
    switch (this->eEvent.type) {
        case sf::Event::KeyPressed:
            this->processKeyInput(true);
            break;
            
        case sf::Event::KeyReleased:
            this->processKeyInput(false);
            break;

        default:
            break;
    }
}

void PlayerInput::processKeyInput(bool bPressed) {
    sf::Keyboard::Key inKey = this->eEvent.key.code;

    switch(inKey) {
        case sf::Keyboard::A:
            this->bLeft = bPressed;
            break;

        case sf::Keyboard::D:
            this->bRight = bPressed;
            break;

        case sf::Keyboard::Num1:
            this->b1 = bPressed;
            break;

        case sf::Keyboard::Num2:
            this->b2 = bPressed;
            break;

        case sf::Keyboard::Num3:
            this->b3 = bPressed;
            break;

        case sf::Keyboard::Space: // temporary
            this->bPartition = bPressed;
            break;

        case sf::Keyboard::Q: // temporary
            this->bZoomOut = bPressed;
            break;

        default:
            break;
    }
}

bool PlayerInput::isLeft() {
    return this->bLeft;
}

bool PlayerInput::isRight() {
    return this->bRight;
}

bool PlayerInput::is1() {
    return this->b1;
}

bool PlayerInput::is2() {
    return this->b2;
}

bool PlayerInput::is3() {
    return this->b3;
}

bool PlayerInput::isPartition()
{
    return this->bPartition;
}

bool components::PlayerInput::isZoomOut()
{
    return this->bZoomOut;
}
