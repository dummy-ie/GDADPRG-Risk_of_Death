#ifndef COMPONENTS_MOVABLE_HPP
#define COMPONENTS_MOVABLE_HPP

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