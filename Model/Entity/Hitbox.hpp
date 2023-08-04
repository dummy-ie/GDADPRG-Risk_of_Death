#ifndef MODELS_HITBOX_HPP
#define MODELS_HITBOX_HPP

#include "../GameObject.hpp"

#include "../Component/Script/Interface/Movable.hpp"

#include "../Component/Script/Mover.hpp"

namespace models {
    class Hitbox : public GameObject, public Movable {
        protected:
            Renderer* pRenderer;
            Mover* pMover;

            sf::Color CColor;
            sf::Shape* pShape;
            sf::FloatRect COffset;

        public:
            Hitbox(std::string strName);
            ~Hitbox();

        public:
            virtual void initialize() = 0;
            virtual bool contains(sf::Vector2f vecLocation) = 0;

        public:
            virtual void move(sf::Time tDeltaTime) = 0;

        public:
            sf::Shape* getShape();
            void setOffset(float fX, float fY);
    };
}

#endif