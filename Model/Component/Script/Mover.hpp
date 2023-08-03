#ifndef COMPONENTS_MOVER_HPP
#define COMPONENTS_MOVER_HPP

#include "../../../Controller/System/PowerUpSystem.hpp"

#include "../../Enum/EnumComponentType.hpp"

#include "../Component.hpp"

#include "Interface/Movable.hpp"

namespace components {
   // using namespace controllers;
    using namespace models;
    class Mover : public Component {
        private:
            Movable* pMovable;
            
            float fTicks;
        
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