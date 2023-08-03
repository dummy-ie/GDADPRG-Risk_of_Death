#ifndef SYSTEMS_POWER_UP_SYSTEM_HPP
#define SYSTEMS_POWER_UP_SYSTEM_HPP

#include "../../Config/Settings.hpp"

#include "../../Model/Pooling/PoolableObject.hpp"

#include "../../Model/Component/Component.hpp"
#include "../../Model/Component/Input/CrosshairMouseInput.hpp"

#include "../../Model/GameObject.hpp"

#include "../Singleton/ObjectPoolManager.hpp"

namespace systems {
    using namespace components;
    using namespace controllers;
    using namespace models;

    class PowerUpSystem : public Component {
        private:
            std::unordered_map<ItemType, float> mapPowerUps;
            float fFrameInterval;
            float fTicks;

        public:
            void perform();
            void activatePowerUp(ItemType EType);
            void clearPowerUp(ItemType EType);
            void clearAll();

            bool isActive(ItemType EType);


        /* * * * * * * * * * * * * * * * * * * * * 
        *       SINGLETON-RELATED CONTENT       * 
        * * * * * * * * * * * * * * * * * * * * */

        private:
            static PowerUpSystem* P_SHARED_INSTANCE;

        private:
            PowerUpSystem(std::string strName);
            PowerUpSystem(const PowerUpSystem&);
            PowerUpSystem& operator = (const PowerUpSystem&);

        public:
            static PowerUpSystem* getInstance();
            static void initialize(std::string strName, GameObject* pParent);
    };
}

#endif