#ifndef COMPONENTS_MOVER_HPP
#define COMPONENTS_MOVER_HPP

#include "../../Enum/EnumComponentType.hpp"

#include "../Component.hpp"

#include "../../../Controller/System/PowerUpSystem.hpp"

#include "Interface/Movable.hpp"

namespace components {
   // using namespace controllers;
    using namespace models;
    using namespace systems;
    class Mover : public Component {
        private:
            Movable* pMovable;
            
            float fSpeedMultiplier;
            float fUpdateTicks;
            float fUpdateTicks2;
        
        public:
            Mover(std::string strName);

        public:
            void perform();

        private:
            void move();

        public:
            void setMovable(Movable* pMoveable);
    };
}

#endif