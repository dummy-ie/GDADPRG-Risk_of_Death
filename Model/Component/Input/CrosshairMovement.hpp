#ifndef COMPONENTS_CROSSHAIR_MOVEMENT_HPP
#define COMPONENTS_CROSSHAIR_MOVEMENT_HPP

#include "../../Enum/EnumComponentType.hpp"

#include "../Component.hpp"
#include "CrosshairMouseInput.hpp"

namespace components {
    class CrosshairMovement : public Component {
        public:
            CrosshairMovement(std::string strName);

        public:
            void perform();
    };
}

#endif