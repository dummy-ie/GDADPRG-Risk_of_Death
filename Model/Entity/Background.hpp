#ifndef MODELS_BACKGROUND_HPP
#define MODELS_BACKGROUND_HPP

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"

#include "../Component/Renderer/Renderer.hpp"

namespace models {
    using namespace components;

    class Background : public GameObject {
        private:
            float fDistance;
        public:
            Background(std::string strName, AnimatedTexture* pTexture);
            Background(std::string strName, AnimatedTexture* pTexture, float fDistance);
            ~Background();
            
        public:
            void initialize();
    };
}

#endif