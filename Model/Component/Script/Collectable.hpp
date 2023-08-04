#ifndef COMPONENTS_COLLECTABLE_HPP
#define COMPONENTS_COLLECTABLE_HPP

#include "../../../Config/Settings.hpp"

#include "../../../Controller/Singleton/TextureManager.hpp"
#include "../../../Controller/Singleton/ObjectPoolManager.hpp"

#include "../../Enum/EnumItemType.hpp"
#include "../../Enum/EnumAssetType.hpp"
#include "../../Enum/EnumComponentType.hpp"
#include "../../Pooling/PoolableObject.hpp"
#include "../../AnimatedTexture.hpp"

#include "../Component.hpp"

namespace models {
    class Item;
}

namespace components {
    using namespace controllers;
    using namespace models;

    class Collectable : public Component {
        private:
            bool bCollected;
            float fTimer;
            float fFrameInterval;
            float fTicks;

        public:
            Collectable(std::string strName);

        public:
            void perform();
            void startTimer();
        
        public:
            bool isCollected();
            void setCollected(bool bCollected);

            sf::Time getDeltaTime();
    };
}

#endif