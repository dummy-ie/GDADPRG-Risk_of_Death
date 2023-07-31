#ifndef SYSTEMS_ITEM_COLLECTOR_SYSTEM_HPP
#define SYSTEMS_ITEM_COLLECTOR_SYSTEM_HPP

#include "../../Model/Pooling/PoolableObject.hpp"

#include "../../Model/Component/Component.hpp"
#include "../../Model/Component/Input/CrosshairMouseInput.hpp"

#include "../../Model/Component/Script/Collectable.hpp"

#include "../../Model/Entity/Crosshair.hpp"
#include "../../Model/GameObject.hpp"

#include "../Singleton/ObjectPoolManager.hpp"

namespace systems {
    using namespace components;
    using namespace controllers;
    using namespace models;

    class ItemCollectorSystem : public Component {
        private:
            std::vector<Collectable*> vecCollectable;

        public:
            void collect(sf::Vector2f vecLocation);

            void perform();
            void registerComponent(Collectable* pCollectable);
            void unregisterComponent(Collectable* pCollectable);

        /* * * * * * * * * * * * * * * * * * * * * 
        *       SINGLETON-RELATED CONTENT       * 
        * * * * * * * * * * * * * * * * * * * * */

        private:
            static ItemCollectorSystem* P_SHARED_INSTANCE;

        private:
            ItemCollectorSystem(std::string strName);
            ItemCollectorSystem(const ItemCollectorSystem&);
            ItemCollectorSystem& operator = (const ItemCollectorSystem&);

        public:
            static ItemCollectorSystem* getInstance();
            static void initialize(std::string strName, GameObject* pParent);
    };
}

#endif