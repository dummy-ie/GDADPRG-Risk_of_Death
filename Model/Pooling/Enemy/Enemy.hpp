#ifndef MODELS_ENEMY_HPP
#define MODELS_ENEMY_HPP

#include "../../../Config/Settings.hpp"

#include "../../Enum/EnumEnemyType.hpp"
#include "../../Enum/EnumPooLTag.hpp"

#include "../PoolableObject.hpp"

namespace models {
    class Enemy : public PoolableObject {
        private:
            EnemyType EType;
            int nHealth;
            float fSpeed;

        public:
            Enemy(PoolTag ETag, std::string strName, AnimatedTexture* pTexture, EnemyType EType, float fX = 0.0f, float fY = 0.0f);
            ~Enemy();

        private:
            void randomizePosition();

        public:
            void initialize();
            void onActivate();
            void onRelease();
            PoolableObject* clone();
        
    };
}

#endif