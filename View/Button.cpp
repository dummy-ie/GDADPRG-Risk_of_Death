#include "Button.hpp"

using namespace views;

Button::Button(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {}

Button::~Button() {}

void Button::initialize() {
    this->setFrame(0);
    this->centerSpriteOrigin();

    Renderer* pRendererComponent = new Renderer(this->strName + " Button");
    pRendererComponent->assignDrawable(this->pSprite);

    this->attachComponent(pRendererComponent);
}

void Button::changeState(ButtonState EState) {
    this->pTexture->setCurrentFrame((int)EState);
    this->setFrame(this->pTexture->getCurrentFrame());
}

void Button::setListener(ButtonListener* pListener) {
    this->pListener = pListener;
    
    ButtonInput* pInputComponent = new ButtonInput(this->strName + " Input", this->pListener);
    this->attachComponent(pInputComponent);
}
