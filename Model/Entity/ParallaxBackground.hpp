#ifndef MODELS_PARALLAX_BACKGROUND_HPP
#define MODELS_PARALLAX_BACKGROUND_HPP

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "Background.hpp"

#include "../Component/Renderer/Renderer.hpp"

namespace models {
    using namespace components;
    class ParallaxBackground : public GameObject {
        public:
            ParallaxBackground(std::string strName);
            ~ParallaxBackground();

        public:
            void addLayer(AnimatedTexture* pTexture, float fDistance);
    };
}

#endif