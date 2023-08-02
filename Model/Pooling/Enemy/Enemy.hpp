#ifndef MODELS_ENEMY_HPP
#define MODELS_ENEMY_HPP

#include "../../../Config/Settings.hpp"

#include "../../Enum/EnumEnemyType.hpp"
#include "../../Enum/EnumPoolTag.hpp"

#include "../../Component/Script/Killable.hpp"
#include "../../Component/Script/Movable.hpp"

#include "../PoolableObject.hpp"

#include "../../../Controller/System/PoolableKillerSystem.hpp"

namespace models {
    using namespace systems;
    class Enemy : public PoolableObject {
        private:
            EnemyType EType;
            int nHealth;
            float fSpeed;
            float fSize;
            float fDistance;

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
            int getHealth();
            float getSpeed();
            float getSize();
            float getDistance();
            void setDistance(float fDistance);
        
    };
}

#endif