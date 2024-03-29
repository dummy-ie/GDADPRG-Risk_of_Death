#include "Text.hpp"

using namespace views;

Text::Text(std::string strName, std::string strText, sf::Font* pFont, int nSize) : GameObject(strName, NULL) {
    this->pText = new sf::Text();
    this->pText->setString(strText);
    this->pText->setFont(*pFont);
    this->pText->setCharacterSize(nSize);
    this->pText->setFillColor(sf::Color(0, 0, 0, 255));
    this->pText->setStyle(sf::Text::Bold);
}

void Text::initialize() {
    Renderer* pRendererComponent = new Renderer(this->strName + " Text");
    pRendererComponent->assignDrawable(this->pText);

    this->attachComponent(pRendererComponent);
    this->fZ = -10.f;
}

sf::Text* Text::getText() {
    return this->pText;
}

void Text::setText(std::string strText, bool bUpdateOrigin) {
    this->pText->setString(strText);
    if(bUpdateOrigin)
        this->pText->setOrigin(this->getGlobalBounds().width / 2.0f, this->getGlobalBounds().height / 2.0f);
}

void Text::setColor(sf::Color CColor) {
    this->pText->setFillColor(CColor);
}

void Text::setPosition(sf::Vector2f vecPosition) {
    GameObject::setPosition(vecPosition);
    this->pText->setPosition(vecPosition);
}

sf::FloatRect Text::getGlobalBounds() {
    return this->pText->getGlobalBounds();
}