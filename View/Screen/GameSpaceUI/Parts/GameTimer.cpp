#include "GameTimer.hpp"

using namespace views;

GameTimer::GameTimer(std::string strName) : View(ViewTag::GAME_TIMER, strName)
{
    this->vecTime = {};
    ViewManager::getInstance()->registerView(this);
}

GameTimer::~GameTimer() {}

void GameTimer::initialize()
{
    this->createTimer();
}

void GameTimer::setTime(float fSeconds)
{
    std::stringstream CStream;
    CStream << std::fixed << std::setprecision(2) << fSeconds;
    std::string strTime = CStream.str();

    if (strTime.length() < 5)
        strTime = "0" + strTime;

    strTime.erase(2, 1);

    for (int i = 0; i < strTime.length(); i++)
    {
        this->vecTime[i]->setText(std::string(1, strTime[i]), false);
    }
}

void GameTimer::createTimer()
{
    std::cout << this->isEnabled() << " creating timer at " << this->getPosition().x << ", " << this->getPosition().y << std::endl;
    // float fScale = 60.f;
    // Text *pColon = new Text(this->strName + " Time",
    //                         ":",
    //                         FontManager::getInstance()->getFont(FontType::DEFAULT),
    //                         fScale);

    // sf::Color CColor = sf::Color::Black;
    // pColon->getText()->setStyle(sf::Text::Bold);
    // pColon->getText()->setOutlineThickness(5.0f);
    // pColon->getText()->setOutlineColor(CColor);
    // this->attachChild(pColon);

    // CColor = sf::Color::Blue;
    // CColor.a = 150;
    // pColon->getText()->setFillColor(CColor);

    // float fX = this->getPosition().x;
    // float fY = this->getPosition().y;
    // pColon->setPosition({fX, fY});

    // fX = pColon->getGlobalBounds().left - pColon->getGlobalBounds().width;
    // fY = pColon->getGlobalBounds().top;
    // float fPadding = 10.f;

    // Text *pText = this->copyText(pColon, "0", fScale);
    // this->vecTime.push_back(pText);
    // fX = fX - ((pColon->getText()->getGlobalBounds().width + fPadding) * 1.5f);
    // fY -= (20.0f);
    // pText->setPosition({fX, fY});

    // pText = this->copyText(pColon, "0", fScale);
    // this->vecTime.push_back(pText);
    // fX = this->vecTime[0]->getPosition().x;
    // fX = fX + (pColon->getText()->getGlobalBounds().width + fPadding);
    // pText->setPosition({fX, fY});

    // pText = this->copyText(pColon, "0", fScale);
    // this->vecTime.push_back(pText);
    // fX = pColon->getPosition().x;
    // fX = fX + (pColon->getText()->getGlobalBounds().width + fPadding);
    // pText->setPosition({fX, fY});

    // pText = this->copyText(pColon, "0", fScale);
    // this->vecTime.push_back(pText);
    // fX = this->vecTime[2]->getPosition().x;
    // fX = fX + (pColon->getText()->getGlobalBounds().width + fPadding);
    // pText->setPosition({fX, fY});

    for (auto &time : vecTime)
    {
        
    }
    
}

Text *GameTimer::copyText(Text *pReference, std::string strText, float fScale)
{
    Text *pText = new Text(this->strName + " Text",
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