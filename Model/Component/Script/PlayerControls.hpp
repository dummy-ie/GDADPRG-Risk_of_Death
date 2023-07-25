#ifndef COMPONENTS_PLAYER_CONTROLS_HPP
#define COMPONENTS_PLAYER_CONTROLS_HPP

#include "../Component.hpp"
#include "../Input/PlayerInput.hpp"

#include "../../Enum/EnumComponentType.hpp"

#include "../../../Controller/Singleton/GameObjectManager.hpp"

namespace components {
    using namespace controllers;

    class PlayerControls : public Component {
        public:
            PlayerControls(std::string strName);

        public:
            void perform();
    };
}

#endif