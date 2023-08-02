#ifndef MODELS_PLAYER_HPP
#define MODELS_PLAYER_HPP

#include "../GameObject.hpp"

#include "../../Model/Component/Input/PlayerInput.hpp"
#include "../../Model/Component/Script/PlayerControls.hpp"

namespace models {
    class Player : public GameObject {
        private:
            int nHealth;
            int nBullets;

        public:
            Player(std::string strName);
            ~Player();

        public:
            void initialize();
        
        public:
            void decrementHealth();
            void decrementBullets();

    };
}

#endif