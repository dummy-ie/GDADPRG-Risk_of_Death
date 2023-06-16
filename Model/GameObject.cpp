#include "GameObject.hpp"

using namespace models;

GameObject::GameObject(std::string strName, AnimatedTexture* pTexture, float fX, float fY) {
    this->bEnabled = true;

    this->strName = strName;
    this->pSprite = new sf::Sprite();
    this->pSprite->setOrigin(0.0f, 0.0f);
    this->pSprite->setPosition(fX, fY);

    this->pTexture = pTexture;
    this->setFrame(0);

    this->vecChildren = {};
    this->vecComponent = {};
}

void GameObject::processInput(sf::Event eEvent) {
    std::vector<Component*> vecInputComponent = this->getComponents(ComponentType::INPUT);
    GeneralInput* pGeneralInput;

    for(Component* pComponent : vecInputComponent) {
        pGeneralInput = (GeneralInput*)pComponent;
        pGeneralInput->assignEvent(eEvent);
        pGeneralInput->perform();
    }

    for(GameObject* pChild : this->vecChildren) {
        pChild->processInput(eEvent);
    }
}

void GameObject::update(sf::Time tDeltaTime) {
    std::vector<Component*> vecScriptComponents = this->getComponents(ComponentType::SCRIPT);
    
    for(Component* pComponent : vecScriptComponents) {
        pComponent->setDeltaTime(tDeltaTime);
        pComponent->perform();
    }

    for(GameObject* pChild : this->vecChildren) {
        pChild->update(tDeltaTime);
    }
}

void GameObject::draw(sf::RenderWindow* pWindow, sf::RenderStates CRenderStates) {
    sf::RenderStates CTransformedRenderStates(CRenderStates);
    CTransformedRenderStates.transform = this->pSprite->getTransform() * CTransformedRenderStates.transform;

    // Add this back in when we have some entities
    /*std::vector<Component*> vecRendererComponent = this->getComponents(ComponentType::RENDERER);
    Renderer* pRenderer;

    for(Component* pComponent : vecRendererComponent) {
        pRenderer = (Renderer*)pComponent;
        pRenderer->assignTargetWindow(pWindow);
        pRenderer->setRenderStates(CRenderStates);
        pRenderer->perform();
    }*/

    for(GameObject* pChild : this->vecChildren) {
        pChild->draw(pWindow, CTransformedRenderStates);
    }
}

void GameObject::attachChild(GameObject* pChild) {
    this->vecChildren.push_back(pChild);
    pChild->initialize();
}

void GameObject::detachChild(GameObject* pChild) {
    int nIndex = -1;
    for(int i = 0; i < this->vecChildren.size() && nIndex == -1; i++) {
        if(this->vecChildren[i] == pChild) {
            nIndex = i;
        }
    }

    if(nIndex != -1)
        this->vecChildren.erase(this->vecChildren.begin() + nIndex);
}

void GameObject::attachComponent(Component* pComponent) {
    this->vecComponent.push_back(pComponent);
    pComponent->attachOwner(this);
}

void GameObject::detachComponent(Component* pComponent) {
    int nIndex = -1;
    for(int i = 0; i < this->vecComponent.size() && nIndex == -1; i++) {
        if(this->vecComponent[i] == pComponent) {
            nIndex = i;
        }
    }

    if(nIndex != -1) {
        this->vecComponent[nIndex]->detachOwner();
        this->vecComponent.erase(this->vecComponent.begin() + nIndex);
    }
}

Component* GameObject::findComponentByName(std::string strName) {
    for(Component* pComponent : this->vecComponent) {
        if(pComponent->getName() == strName)
        return pComponent;
    }
    
    std::cout << "[ERROR] : Component [" << strName << "] NOT found." << std::endl;
    return NULL;
}

std::vector<Component*> GameObject::getComponents(ComponentType EType) {
    std::vector<Component*> vecFound = {};

    for(Component* pComponent : this->vecComponent) {
        if(pComponent->getType() == EType)
            vecFound.push_back(pComponent);
    }

    return vecFound;
}

void GameObject::setAnimationType(AnimationType EAnimationType) {
    this->pTexture = this->mapAnimatedTexture[EAnimationType];
    this->pTexture->setCurrentFrame(0);
}

void GameObject::incrementFrame() {
    this->pTexture->incrementFrame();
    this->setFrame(this->pTexture->getCurrentFrame());
}

void GameObject::centerSpriteOrigin() {
    if(this->pTexture != NULL) {
        int nWidth = this->pSprite->getTexture()->getSize().x;
        int nHeight = this->pSprite->getTexture()->getSize().y;

        float fHalfWidth = nWidth / 2.0f;
        float fHalfHeight = nHeight / 2.0f;

        this->pSprite->setOrigin(fHalfWidth, fHalfHeight);
    }
}

void GameObject::setFrame(int nFrame) {
    if(this->pTexture != NULL) {
        this->pTexture->setCurrentFrame(nFrame);
        this->pSprite->setTexture(*this->pTexture->getFrame(), true);
    }
}

bool GameObject::isEnabled() {
    return this->bEnabled;
}

void GameObject::setEnabled(bool bEnabled) {
    this->bEnabled = bEnabled;
}

std::string GameObject::getName() {
    return this->strName;
}

int GameObject::getFrameSize() {
    if(this->pTexture != NULL) {
        return this->pTexture->getFrameSize();
    }
    return -1;
}

int GameObject::getCurrentFrame() {
    if(this->pTexture != NULL) {
        return this->pTexture->getCurrentFrame();
    }
    return -1;
}

sf::Sprite* GameObject::getSprite() {
    return this->pSprite;
}
