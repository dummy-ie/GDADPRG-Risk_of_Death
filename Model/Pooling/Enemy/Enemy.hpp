#ifndef MODELS_ENEMY_HPP
#define MODELS_ENEMY_HPP

#include "../../../Config/Settings.hpp"

#include "../../Enum/EnumEnemyType.hpp"
#include "../../Enum/EnumHitboxType.hpp"
#include "../../Enum/EnumPoolTag.hpp"

#include "../../Component/Script/Killable.hpp"
#include "../../Component/Script/Mover.hpp"
#include "../../Component/Script/Switcher.hpp"

#include "../../Component/Script/Interface/Movable.hpp"
#include "../../Component/Script/Interface/Switchable.hpp"

#include "../PoolableObject.hpp"

#include "../../../Controller/System/PoolableKillerSystem.hpp"
#include "../../../Controller/System/ViewSwitcherSystem.hpp"
#include "../../../Controller/System/PowerUpSystem.hpp"

namespace models {
    using namespace controllers;
    using namespace systems;
    class Enemy : public PoolableObject, public Movable, public Switchable {
        private:
            Mover* pMover;
            Switcher* pSwitcher;
            Renderer* pSpriteRenderer;
            Renderer* pRectangleRenderer;
            Renderer* pHitboxRenderer;

            EnemyType EType;
            HitboxType EHitbox;
            sf::Color CColor;
            sf::RectangleShape* pRectangle;
            sf::Shape* pHitbox;
            sf::FloatRect CHitbox;

            int nHealth;
            float fSpeed;
            float fSize;

        public:
            Enemy(PoolTag ETag, std::string strName, AnimatedTexture* pTexture, EnemyType EType, HitboxType EHitbox);
            ~Enemy();

        public:
            void initialize();
            void onActivate();
            void onRelease();
            PoolableObject* clone();

        public:
            void move(sf::Time tDeltaTime);
            bool contains(sf::Vector2f vecLocation);
            void switchLeftView();
            void switchFrontView();

        private:
            void randomizePosition();
            void initializeType();
            void initializeHitbox();

        public:
            void decrementHealth();

        public:
            int getHealth();
            float getSize();
            EnemyType getType();
        
    };
}

#endif