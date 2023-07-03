#include "TitleScreen.hpp"

using namespace views;

TitleScreen::TitleScreen(std::string strName) : View(ViewTag::TITLE_SCREEN, strName) {
    ViewManager::getInstance()->registerView(this);
}

TitleScreen::~TitleScreen() {}

void TitleScreen::initialize() {
    float fSpacing = 100;

    Text* pText = new Text(this->strName + " Title", "Risk of Death", FontManager::getInstance()->getFont(FontType::DEFAULT), 64);
    float fWidth = pText->getText()->getLocalBounds().width;
    pText->getText()->setPosition(SCREEN_WIDTH / 2 - fWidth / 2, 21);
    this->attachChild(pText);

    this->pStart = new Text(this->strName + " Start", "Start", FontManager::getInstance()->getFont(FontType::DEFAULT), 24);
    this->attachChild(this->pStart);
    fWidth = this->pStart->getText()->getLocalBounds().width;
    this->pStart->getText()->setPosition(SCREEN_WIDTH / 2 - fWidth / 2, 200);
    sf::FloatRect CBounds = this->pStart->getText()->getGlobalBounds();
    Button* pButton = new Button(this->strName + " Start Button", CBounds);
    this->attachChild(pButton);
    pButton->setListener(this);

    this->pLeaderboards = new Text(this->strName + " Leaderboards", "Leaderboards", FontManager::getInstance()->getFont(FontType::DEFAULT), 24);
    this->attachChild(this->pLeaderboards);
    fWidth = this->pLeaderboards->getText()->getLocalBounds().width;
    this->pLeaderboards->getText()->setPosition(SCREEN_WIDTH / 2 - fWidth / 2, 200 + fSpacing);
    CBounds = this->pLeaderboards->getText()->getGlobalBounds();
    pButton = new Button(this->strName + " Leaderboards Button", CBounds);
    this->attachChild(pButton);
    pButton->setListener(this);

    this->pExit = new Text(this->strName + " Exit", "Exit", FontManager::getInstance()->getFont(FontType::DEFAULT), 24);
    this->attachChild(this->pExit);
    fWidth = this->pExit->getText()->getLocalBounds().width;
    this->pExit->getText()->setPosition(SCREEN_WIDTH / 2 - fWidth / 2, 200 + fSpacing * 2);
    CBounds = this->pExit->getText()->getGlobalBounds();
    pButton = new Button(this->strName + " Exit Button", CBounds);
    this->attachChild(pButton);
    pButton->setListener(this);
}

void TitleScreen::onClick(Button* pButton) {
    // buggy
    if (pButton->getName().find("Start Button") != std::string::npos)
        this->pStart->setColor(sf::Color::White);
    if (pButton->getName().find("Leaderboards Button") != std::string::npos)
        this->pLeaderboards->setColor(sf::Color::White);
    if (pButton->getName().find("Exit Button") != std::string::npos)
        this->pExit->setColor(sf::Color::White);
    
}

void TitleScreen::onRelease(Button* pButton) {
    if (pButton->getName().find("Start Button") != std::string::npos) {
        std::cout << "[GAME START]" << std::endl;
        this->pStart->setColor(sf::Color::Black);
    }
    if (pButton->getName().find("Leaderboards Button") != std::string::npos) {
        std::cout << "[LEADERBOARDS]" << std::endl;
        this->pLeaderboards->setColor(sf::Color::Black);
    }
    if (pButton->getName().find("Exit Button") != std::string::npos) {
        std::cout << "[GAME EXIT]" << std::endl;
        this->pExit->setColor(sf::Color::Black);
    }
}