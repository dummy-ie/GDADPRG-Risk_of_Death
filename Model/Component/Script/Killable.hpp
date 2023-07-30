#ifndef COMPONENTS_KILLABLE_HPP
#define COMPONENTS_KILLABLE_HPP

#include "../../../Controller/Singleton/TextureManager.hpp"
#include "../../../Controller/Singleton/ObjectPoolManager.hpp"

#include "../../Enum/EnumAnimationType.hpp"
#include "../../Enum/EnumAssetType.hpp"
#include "../../Enum/EnumComponentType.hpp"
#include "../../Pooling/PoolableObject.hpp"
#include "../../AnimatedTexture.hpp"

#include "../Component.hpp"

namespace models {
    class Enemy;
}

namespace components {
    using namespace controllers;
    using namespace models;

    class Killable : public Component {
        private:
            float fFrameInterval;
            float fTicks;
            bool bKilled;

        public:
            Killable(std::string strName, float fFrameInterval);

        public:
            void perform();
        
        public:
            bool isKilled();
            void setKilled(bool bKilled);
    };
}

#endif