#ifndef MODELS_CROSSHAIR_HPP
#define MODELS_CROSSHAIR_HPP

#include "GameObject.hpp"
#include "AnimatedTexture.hpp"

#include "Component/CrosshairMouseInput.hpp"
#include "Component/CrosshairMovement.hpp"

namespace models {
    class Crosshair : public GameObject {
        public:
            Crosshair(std::string strName, AnimatedTexture* pTexture, float fX = 0.0f, float fY = 0.0f);
            ~Crosshair();
            
        public:
            void initialize();
    };
}

#endif