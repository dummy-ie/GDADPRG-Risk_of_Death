#ifndef MODELS_PLAYER_HPP
#define MODELS_PLAYER_HPP

#include "../GameObject.hpp"

#include "../Component/Input/PlayerInput.hpp"
#include "../Component/Script/PlayerControls.hpp"

#include "../Component/Script/Reloader.hpp"
#include "../Component/Script/Interface/Reloadable.hpp"

namespace models {
    using namespace components;
    using namespace interfaces;
    class Player : public GameObject, public Reloadable {
        private:
            Reloader* pReloader = NULL;
            bool bIsZoomedIn = false;
            int nHealth;
            int nBullets;

        public:
            Player(std::string strName);
            ~Player();

        public:
            void initialize();
            void start();
            void stop();
            void reload();

        public:
            void decrementHealth();
            void decrementBullets();

        public:
            void setZoomedIn(bool bIsZoomedIn);
            bool isZoomedIn();
            bool hasBullets();
            Reloader* getReloader();

    };
}

#endif