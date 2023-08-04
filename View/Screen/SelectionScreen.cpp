#include "SelectionScreen.hpp"

using namespace views;

SelectionScreen::SelectionScreen(std::string strName) : View(ViewTag::TITLE_SCREEN, strName) {
    ViewManager::getInstance()->registerView(this);
    this->nRows = 1;
    this->nColumns = 1;
}

SelectionScreen::~SelectionScreen() {}

void SelectionScreen::initialize() {
    float fSpacing = 100;

    Text* pText = new Text(this->strName + " Title", "Pre-game Setup", FontManager::getInstance()->getFont(FontType::DEFAULT), 64);
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

    this->pRows = new Text(this->strName + " Row", "Rows: " + std::to_string(this->nRows),FontManager::getInstance()->getFont(FontType::DEFAULT), 24);
    this->attachChild(this->pRows);
    fWidth = this->pStart->getText()->getLocalBounds().width;
    this->pRows->getText()->setPosition(SCREEN_WIDTH / 2 - fWidth - fSpacing, 200 + fSpacing);
    CBounds = this->pRows->getText()->getGlobalBounds();
    pButton = new Button(this->strName + " Row Button", CBounds);
    this->attachChild(pButton);
    pButton->setListener(this);

    this->pColumns = new Text(this->strName + " Column", "Columns: " + std::to_string(this->nColumns),FontManager::getInstance()->getFont(FontType::DEFAULT), 24);
    this->attachChild(this->pColumns);
    fWidth = this->pStart->getText()->getLocalBounds().width;
    this->pColumns->getText()->setPosition(SCREEN_WIDTH / 2 - fWidth / 2 + fSpacing, 200 + fSpacing);
    CBounds = this->pColumns->getText()->getGlobalBounds();
    pButton = new Button(this->strName + " Column Button", CBounds);
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

void SelectionScreen::onClick(Button* pButton) {
    // buggy
    if (pButton->getName().find("Start Button") != std::string::npos){
        this->pStart->setColor(sf::Color::White);
    }
        
    if (pButton->getName().find("Row Button") != std::string::npos){
        this->pRows->setColor(sf::Color::White);
    }

    if (pButton->getName().find("Column Button") != std::string::npos){
        this->pColumns->setColor(sf::Color::White);
    }

    if (pButton->getName().find("Exit Button") != std::string::npos){
        this->pExit->setColor(sf::Color::White);
    }
    
}

void SelectionScreen::onHover(Button *pButton)
{
    if (pButton->getName().find("Start Button") != std::string::npos)
        this->pStart->setColor(sf::Color::Green);
    
    if (pButton->getName().find("Row Button") != std::string::npos)
        this->pRows->setColor(sf::Color::Green);

    if (pButton->getName().find("Column Button") != std::string::npos)
        this->pColumns->setColor(sf::Color::Green);

    if (pButton->getName().find("Exit Button") != std::string::npos)
        this->pExit->setColor(sf::Color::Green);
    
}

void SelectionScreen::onRelease(Button* pButton) {
    if (pButton->getName().find("Start Button") != std::string::npos) {
        std::cout << "[GAME START]" << std::endl;
        WindowManager::getInstance()->generatePartitions(this->nColumns,this->nRows);
        SceneManager::getInstance()->loadScene(SceneTag::GAME_SPACE);
    }
    if (pButton->getName().find("Row Button") != std::string::npos) {
        std::cout << "[SET ROW]" << std::endl;
        this->nRows++;
        if(this->nRows > 2){
            this->nRows = 1;
        }
        this->pRows->setText("Rows: " + std::to_string(this->nRows));
    }
    if (pButton->getName().find("Column Button") != std::string::npos) {
        std::cout << "[SET COLUMN]" << std::endl;
        this->nColumns++;
        if(this->nColumns > 3){
            this->nColumns = 1;
        }
        this->pColumns->setText("Columns: " + std::to_string(this->nColumns));
    }
    if (pButton->getName().find("Exit Button") != std::string::npos) {
        std::cout << "[EXIT]" << std::endl;
        SceneManager::getInstance()->loadScene(SceneTag::GAME_MENU);
    }
}

void SelectionScreen::reset(Button* pButton) {
    if (pButton->getName().find("Start Button") != std::string::npos) {
        this->pStart->setColor(sf::Color::Black);
    }
    if (pButton->getName().find("Row Button") != std::string::npos){
        this->pRows->setColor(sf::Color::Black);
    }
    if (pButton->getName().find("Column Button") != std::string::npos){
        this->pColumns->setColor(sf::Color::Black);
    }
    if (pButton->getName().find("Exit Button") != std::string::npos) {
        this->pExit->setColor(sf::Color::Black);
    }
}