#ifndef CONTROLLERS_GAME_HPP
#define CONTROLLERS_GAME_HPP

#include "../Config/Settings.hpp"

namespace controllers {
    class Game {
        private:
            sf::RenderWindow rwWindow;

        public:
            Game();

        public:
            void run();
        
        private:
            void processEvents();
            void update(sf::Time tDeltaTime);
            void render();
    };
}

#endif