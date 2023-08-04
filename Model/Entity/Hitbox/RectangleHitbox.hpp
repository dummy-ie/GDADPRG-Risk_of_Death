#ifndef MODELS_RECTANGLE_HITBOX_HPP
#define MODELS_RECTANGLE_HITBOX_HPP

#include "../Hitbox.hpp"

namespace models {
    class RectangleHitbox : public Hitbox {
        public:
            RectangleHitbox(std::string strName);
            ~RectangleHitbox();

        public:
            void initialize();
            bool contains(sf::Vector2f vecLocation);
            void move(sf::Time tDeltaTime);
    };
}

#endif