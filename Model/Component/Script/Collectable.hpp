#ifndef COMPONENTS_COLLECTABLE_HPP
#define COMPONENTS_COLLECTABLE_HPP

#include "../../../Controller/Singleton/TextureManager.hpp"
#include "../../../Controller/Singleton/ObjectPoolManager.hpp"

#include "../../Enum/EnumItemType.hpp"
#include "../../Enum/EnumAssetType.hpp"
#include "../../Enum/EnumComponentType.hpp"
#include "../../Pooling/PoolableObject.hpp"
#include "../../Pooling/Item/Item.hpp"
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

        public:
            Collectable(std::string strName);

        public:
            void perform();
        
        public:
            bool isCollected();
            void setCollected(bool bCollected);
    };
}

#endif