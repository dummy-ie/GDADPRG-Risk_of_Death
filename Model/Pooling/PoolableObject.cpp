#include "PoolableObject.hpp"

using namespace models;

PoolableObject::PoolableObject(PoolTag ETag, std::string strName, AnimatedTexture* pTexture, float fX, float fY)
               : GameObject(strName, pTexture, fX, fY) {
    this->ETag = ETag;
}

PoolableObject::~PoolableObject() {}

PoolTag PoolableObject::getTag() {
    return this->ETag;
}
