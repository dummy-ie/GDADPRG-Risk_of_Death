#include "GameTimer.hpp"

using namespace views;

GameTimer::GameTimer(std::string strName) : View(ViewTag::GAME_TIMER, strName) {
    this->vecTime = {};
}

GameTimer::~GameTimer() {}

void GameTimer::initialize() {
    this->createTimer();
}

void GameTimer::createTimer() {
    float fScale = 310 * SCREEN_SCALE;
    Text* pColon = new Text(this->strName + " Time",
                            ":",
                            FontManager::getInstance()->getFont(FontType::DEFAULT),
                            fScale);

    sf::Color CColor = sf::Color::White;
    this->attachChild(pColon);
    pColon->getText()->setStyle(sf::Text::Bold);
    pColon->getText()->setOutlineThickness(5.0f * SCREEN_SCALE);
    pColon->getText()->setOutlineColor(CColor);

    CColor = sf::Color::Blue;
    CColor.a = 150;
    pColon->getText()->setFillColor(CColor);

    float fX = SCREEN_WIDTH / 2.0f - (68.0f * SCREEN_SCALE);
    float fY = (SCREEN_HEIGHT / 2.0f) - (280.0f * SCREEN_SCALE);
    pColon->setPosition({fX, fY});

    fX = pColon->getGlobalBounds().left - pColon->getGlobalBounds().width;
    fY = pColon->getGlobalBounds().top;
    float fPadding = (100.0f * SCREEN_SCALE);

    Text* pText = this->copyText(pColon, "0", fScale);
    this->vecTime.push_back(pText);
    fX = fX - ((pColon->getText()->getGlobalBounds().width + fPadding) * 1.5f);
    fY -= (20.0f * SCREEN_SCALE);
    pText->setPosition({fX, fY});

    pText = this->copyText(pColon, "0", fScale);
    this->vecTime.push_back(pText);
    fX = this->vecTime[0]->getPosition().x;
    fX = fX + (pColon->getText()->getGlobalBounds().width + fPadding);
    pText->setPosition({fX, fY});

    pText = this->copyText(pColon, "0", fScale);
    this->vecTime.push_back(pText);
    fX = pColon->getPosition().x;
    fX = fX + (pColon->getText()->getGlobalBounds().width + fPadding) + (2.0f * SCREEN_SCALE);
    pText->setPosition({fX, fY});

    pText = this->copyText(pColon, "0", fScale);
    this->vecTime.push_back(pText);
    fX = this->vecTime[2]->getPosition().x;
    fX = fX + (pColon->getText()->getGlobalBounds().width + fPadding);
    pText->setPosition({fX, fY});
}

Text* GameTimer::copyText(Text* pReference, std::string strText, float fScale) {
    Text* pText = new Text(this->strName + " Text",
                           strText,
                           FontManager::getInstance()->getFont(FontType::DEFAULT),
                           fScale);

    this->attachChild(pText);

    pText->getText()->setStyle(pReference->getText()->getStyle());
    pText->getText()->setOutlineThickness(pReference->getText()->getOutlineThickness());
    pText->getText()->setOutlineColor(pReference->getText()->getOutlineColor());
    pText->getText()->setFillColor(pReference->getText()->getFillColor());

    pText->setPosition(pReference->getPosition());

    return pText;
}