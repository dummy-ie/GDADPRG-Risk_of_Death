#include "CrosshairMouseInput.hpp"

using namespace components;

CrosshairMouseInput::CrosshairMouseInput(std::string strName) : GeneralInput(strName) {
    this->bLeftClick = false;
    this->bRightClick = false;
    this->vecLocation = sf::Vector2f(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);
}

void CrosshairMouseInput::perform() {
    switch(this->eEvent.type) {
        case sf::Event::MouseButtonPressed:
            this->processMouseInput(this->eEvent.mouseButton.button, true);
            break;
            
        case sf::Event::MouseButtonReleased:
            this->processMouseInput(this->eEvent.mouseButton.button, false);
            break;

        case sf::Event::MouseMoved:
            this->vecLocation.x = this->eEvent.mouseMove.x;
            this->vecLocation.y = this->eEvent.mouseMove.y;
            break;

        default:
            break;
    }
}

void CrosshairMouseInput::processMouseInput(sf::Mouse::Button inMouse, bool bPressed) {
    Player* pPlayer = (Player*)GameObjectManager::getInstance()->findObjectByName("Player");
    switch(inMouse) {
        case sf::Mouse::Left:
            this->bLeftClick = bPressed;
            if(this->bLeftClick) {
                std::cout << "CrosshairMouseInput::processMouseInput() >> [LEFT]." << std::endl;
                
                bool bPlayerHasToZoom = !pPlayer->isZoomedIn() && WindowManager::getInstance()->getPartitions()->size() > 1; // if the player isn't zoomed in AND there is more than 1 view on the partitions (more than 1x1)
                if (!bPlayerHasToZoom && pPlayer->hasBullets() && !pPlayer->getReloader()->isReloading()) {
                    pPlayer->decrementBullets();
                    SFXManager::getInstance()->getSound(SFXType::PLAYER_SHOOT)->play();
                }
                else if (bPlayerHasToZoom)
                {
                    pPlayer->setZoomedIn(WindowManager::getInstance()->mouseOverSubscreen(this->vecLocation));
                    this->resetLeftClick();
                }
            }
            break;

        case sf::Mouse::Right:
            this->bRightClick = bPressed;
            break;

        default:
            break;
    }
}

void CrosshairMouseInput::resetLeftClick() {
    this->bLeftClick = false;
}

bool CrosshairMouseInput::isLeftClick() {
    return this->bLeftClick;
}

bool CrosshairMouseInput::isRightClick() {
    return this->bRightClick;
}

sf::Vector2f CrosshairMouseInput::getLocation() {
    return this->vecLocation;
}
