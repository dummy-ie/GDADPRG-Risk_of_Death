#ifndef MODELS_ENEMY_HPP
#define MODELS_ENEMY_HPP

#include "../../../Config/Settings.hpp"

#include "../../Enum/EnumEnemyType.hpp"
#include "../../Enum/EnumPoolTag.hpp"

#include "../../Component/Script/Killable.hpp"
#include "../../Component/Script/Mover.hpp"

#include "../../Component/Script/Interface/Movable.hpp"

#include "../PoolableObject.hpp"

#include "../../../Controller/System/PoolableKillerSystem.hpp"
#include "../../../Controller/System/PowerUpSystem.hpp"

namespace models {
    using namespace systems;
    class Enemy : public PoolableObject, public Movable {
        private:
            Mover* pMover;
            Renderer* pSpriteRenderer;
            Renderer* pRectangleRenderer;

            EnemyType EType;
            sf::Color CColor;
            sf::RectangleShape* pRectangle;

            int nHealth;
            float fSpeed;
            float fSize;

            //float fTop;

        public:
            Enemy(PoolTag ETag, std::string strName, AnimatedTexture* pTexture, EnemyType EType);
            ~Enemy();

        private:
            void randomizePosition();
            void initializeType();

        public:
            void decrementHealth();

        public:
            void initialize();
            void onActivate();
            void onRelease();
            PoolableObject* clone();

        public:
            void move(sf::Time tDeltaTime);

        public:
            int getHealth();
            float getSize();
        
    };
}

#endif