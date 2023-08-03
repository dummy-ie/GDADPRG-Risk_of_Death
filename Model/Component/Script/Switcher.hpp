#ifndef COMPONENTS_SWITCHER_HPP
#define COMPONENTS_SWITCHER_HPP

#include "../../Enum/EnumComponentType.hpp"

#include "../Component.hpp"

#include "../../../Controller/System/PowerUpSystem.hpp"

#include "Interface/Switchable.hpp"

namespace components {
    using namespace models;
    using namespace systems;
    class Switcher : public Component {
        private:
            Switchable* pSwitchable;
            bool bSwitching;
            float fTicks;
        
        public:
            Switcher(std::string strName);

        public:
            void perform();
            void start();
            void stop();
            void switchLeftView();
            void switchFrontView();

        private:

        public:
            void setSwitchable(Switchable* pSwitchable);
    };
}

#endif