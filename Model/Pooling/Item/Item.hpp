#ifndef MODELS_ITEM_HPP
#define MODELS_ITEM_HPP

#include "../../../Config/Settings.hpp"

#include "../../Enum/EnumItemType.hpp"
#include "../../Enum/EnumPoolTag.hpp"

#include "../../Component/Script/Collectable.hpp"

#include "../PoolableObject.hpp"

#include "../../../Controller/Singleton/ItemManager.hpp"
#include "../../../Controller/System/ItemCollectorSystem.hpp"

namespace models {
    using namespace systems;
    class Item : public PoolableObject {
        private:
            ItemType EType;

        public:
            Item(PoolTag ETag, std::string strName, AnimatedTexture* pTexture, ItemType EType, float fX = 0.0f, float fY = 0.0f);
            ~Item();

        private:
            //void randomizePosition();
            void randomizeType();

        public:
            void initialize();
            void collect();
            void onActivate();
            void onRelease();
            PoolableObject* clone();
        
    };
}

#endif