#include "Collider.hpp"

using namespace components;

Collider::Collider(std::string strName) : Component(strName, ComponentType::PHYSICS) {
    this->COffset = sf::FloatRect(0.0f, 0.0f, 0.0f, 0.f);
    this->vecCollided = {};
    this->bCleanUp = false;
}

void Collider::perform() {}

bool Collider::isColliding(Collider* pCollider) {
    sf::FloatRect CBoundsA = this->getGlobalBounds();
    sf::FloatRect CBoundsB = pCollider->getGlobalBounds();

    return CBoundsA.intersects(CBoundsB);
}

int Collider::findCollider(Collider* pCollider) {
    int nIndex = -1;

    for(int i = 0; i < this->vecCollided.size() && nIndex == -1; i++) {
        if(pCollider == this->vecCollided[i])
            nIndex = i;
    }

    return nIndex;
}

void Collider::cleanCollisions() {
    this->vecCollided.clear();
}

void Collider::onCollisionEnter(GameObject* pGameObject) {
    if(this->pListener != NULL) {
        this->pListener->onCollisionEnter(pGameObject);
    }
}

void Collider::onCollisionContinue(GameObject* pGameObject) {
    if(this->pListener != NULL) {
        this->pListener->onCollisionContinue(pGameObject);
    }
}

void Collider::onCollisionExit(GameObject* pGameObject) {
    if(this->pListener != NULL) {
        this->pListener->onCollisionExit(pGameObject);
    }
}

void Collider::setListener(CollisionListener* pListener) {
    this->pListener = pListener;
}

void Collider::setOffset(sf::FloatRect COffset) {
    this->COffset = COffset;
}

bool Collider::hasCollided(Collider* pCollider) {
    if(this->findCollider(pCollider) != -1)
        return true;

    return false;
}

void Collider::setCollided(Collider* pCollider, bool bCollided) {
    if(bCollided)
        this->vecCollided.push_back(pCollider);

    else {
        int nIndex = this->findCollider(pCollider);

        if(nIndex != -1)
            this->vecCollided.erase(this->vecCollided.begin() + nIndex);
    }
}

bool Collider::isCleanUp() {
    return this->bCleanUp;
}

void Collider::setCleanUp(bool bCleanUp) {
    this->bCleanUp = bCleanUp;
}

sf::FloatRect Collider::getGlobalBounds() {
    sf::FloatRect CTransform = this->getOwner()->getGlobalBounds();
    
    CTransform.left = CTransform.left + this->COffset.left;
    CTransform.top = CTransform.top + this->COffset.top;
    CTransform.width = CTransform.width + this->COffset.width;
    CTransform.height = CTransform.height + this->COffset.height;

    return CTransform;
}
