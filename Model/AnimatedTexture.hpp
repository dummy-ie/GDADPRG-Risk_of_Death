#ifndef MODELS_ANIMATED_TEXTURE_H
#define MODELS_ANIMATED_TEXTURE_H

#include "Enum/EnumAssetType.hpp"

namespace models {
    class AnimatedTexture {
        private:
            AssetType EType;
            std::vector<sf::Texture*> vecFrames;
            int nCurrentFrame;
        
        public:
            AnimatedTexture(AssetType EType = AssetType::NONE, std::vector<sf::Texture*> vecFrames = {});

        public:
            void incrementFrame();

        public:
            sf::Texture* getFrame();
            int getFrameSize();
            int getCurrentFrame();
            void setCurrentFrame(int nCurrentFrame);
    };
}

#endif