#ifndef MODELS_TRIANGLE_HITBOX_HPP
#define MODELS_TRIANGLE_HITBOX_HPP

#include "../Hitbox.hpp"

namespace models {
    class TriangleHitbox : public Hitbox {
        public:
            TriangleHitbox(std::string strName);
            ~TriangleHitbox();

        public:
            void initialize();
            bool contains(sf::Vector2f vecLocation);
            void move(float fTicks, sf::Time tDeltaTime);

        private:
            float calculateArea(sf::Vector2f vecPoint1, sf::Vector2f vecPoint2, sf::Vector2f vecPoint3);
    };
}

#endif