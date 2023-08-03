#ifndef COMPONENTS_CROSSHAIR_MOUSE_INPUT_HPP
#define COMPONENTS_CROSSHAIR_MOUSE_INPUT_HPP

#include "../../../Config/Settings.hpp"
#include "../../Enum/EnumComponentType.hpp"
#include "../../Enum/EnumSFXType.hpp"

#include "../../../Controller/Singleton/SFXManager.hpp"

#include "../../../Controller/Singleton/GameObjectManager.hpp"

#include "../../Entity/Player.hpp"

#include "../../../View/Screen/GameSpaceUI/GameSpaceUI.hpp"

#include "GeneralInput.hpp"

namespace components {
    using namespace controllers;
    using namespace models;
    class CrosshairMouseInput : public GeneralInput {
        private:
            bool bLeftClick;
            bool bRightClick;
            sf::Vector2f vecLocation;

        public:
            CrosshairMouseInput(std::string strName);

        public:
            void perform();
        
        private:
            void processMouseInput(sf::Mouse::Button inMouse, bool bPressed);

        public:
            void resetLeftClick();
            bool isLeftClick();
            bool isRightClick();
            sf::Vector2f getLocation();
    };
}

#endif