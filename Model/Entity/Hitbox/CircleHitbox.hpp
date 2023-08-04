#ifndef MODELS_CIRCLE_HITBOX_HPP
#define MODELS_CIRCLE_HITBOX_HPP

#include "../Hitbox.hpp"

namespace models {
    class CircleHitbox : public Hitbox {
        public:
            CircleHitbox(std::string strName);
            ~CircleHitbox();

        public:
            void initialize();
            bool contains(sf::Vector2f vecLocation);
            void move(sf::Time tDeltaTime);
    };
}

#endif