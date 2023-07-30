#ifndef SYSTEMS_POOLABLE_KILLER_SYSTEM_HPP
#define SYSTEMS_POOLABLE_KILLER_SYSTEM_HPP

#include "../../Model/Pooling/PoolableObject.hpp"

#include "../../Model/Component/Component.hpp"
#include "../../Model/Component/Input/CrosshairMouseInput.hpp"
//#include "../../Model/Component/Idleable.hpp"
#include "../../Model/Component/Script/Killable.hpp"

#include "../../Model/Entity/Crosshair.hpp"
#include "../../Model/GameObject.hpp"

#include "../Singleton/ObjectPoolManager.hpp"

namespace systems {
    using namespace components;
    using namespace controllers;
    using namespace models;

    class PoolableKillerSystem : public Component {
        private:
            std::vector<Killable*> vecKillable;

        public:
            void kill(sf::Vector2f vecLocation);

            void perform();
            void registerComponent(Killable* pKillable);
            void unregisterComponent(Killable* pKillable);

        /* * * * * * * * * * * * * * * * * * * * * 
        *       SINGLETON-RELATED CONTENT       * 
        * * * * * * * * * * * * * * * * * * * * */

        private:
            static PoolableKillerSystem* P_SHARED_INSTANCE;

        private:
            PoolableKillerSystem(std::string strName);
            PoolableKillerSystem(const PoolableKillerSystem&);
            PoolableKillerSystem& operator = (const PoolableKillerSystem&);

        public:
            static PoolableKillerSystem* getInstance();
            static void initialize(std::string strName, GameObject* pParent);
    };
}

#endif