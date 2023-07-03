#include "TitleScreen.hpp"

using namespace views;

TitleScreen::TitleScreen(std::string strName) : View(ViewTag::TITLE_SCREEN, strName) {
    ViewManager::getInstance()->registerView(this);
}

TitleScreen::~TitleScreen() {}

void TitleScreen::initialize() {
    Text* pText = new Text(this->strName + " Title", "Risk of Death", FontManager::getInstance()->getFont(FontType::DEFAULT), 64);
    float fWidth = pText->getText()->getLocalBounds().width;
    pText->getText()->setPosition(SCREEN_WIDTH / 2 - fWidth / 2, 21);
    this->attachChild(pText);
}