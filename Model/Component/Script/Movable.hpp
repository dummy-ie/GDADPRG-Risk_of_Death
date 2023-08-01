#ifndef COMPONENTS_MOVABLE_HPP
#define COMPONENTS_MOVABLE_HPP

#include "../../Enum/EnumComponentType.hpp"
#include "../../Pooling/PoolableObject.hpp"

#include "../../Pooling/Enemy/Enemy.hpp"

#include "../Component.hpp"

namespace models {
    class Enemy;
}

namespace components {
   // using namespace controllers;
    using namespace models;
    class Movable : public Component {
        private:
            float fTicks;
        
        public:
            Movable(std::string strName);

        public:
            void perform();
    };
}

#endif