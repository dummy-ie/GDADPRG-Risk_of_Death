#ifndef COMPONENTS_DIRECTION_SWAP_HPP
#define COMPONENTS_DIRECTION_SWAP_HPP

#include "../../../Config/Settings.hpp"

#include "../../Enum/EnumComponentType.hpp"

#include "../Component.hpp"

namespace components {
    using namespace models;
    class DirectionSwap : public Component {
        private:
            float fSwitchInterval;
            float fTicks;

            bool bDirection;
        
        public:
            DirectionSwap(std::string strName);

        public:
            void perform();

        public:
            bool getDirection();
    };
}

#endif