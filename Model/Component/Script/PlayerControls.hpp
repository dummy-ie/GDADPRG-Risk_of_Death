#ifndef COMPONENTS_PLAYER_CONTROLS_HPP
#define COMPONENTS_PLAYER_CONTROLS_HPP

#include "../Component.hpp"
#include "../Input/PlayerInput.hpp"

#include "../../Enum/EnumComponentType.hpp"
#include "../../Enum/EnumItemType.hpp"

#include "../../../Controller/Singleton/GameObjectManager.hpp"
#include "../../../Controller/Singleton/WindowManager.hpp"
#include "../../../Controller/Singleton/ItemManager.hpp"

//#include "../../../Controller/System/EventBroadcaster.hpp"

namespace components {
    using namespace controllers;

    class PlayerControls : public Component {
        private:
            std::vector<float> vecTimer;
            float fCooldown;
            float fTicks;

        public:
            PlayerControls(std::string strName);

        public:
            void perform();
    };
}

#endif