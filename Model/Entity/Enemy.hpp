#ifndef MODELS_ENEMY_HPP
#define MODELS_ENEMY_HPP

#include "../Enum/EnumEnemyType.hpp"
#include "../Enum/EnumPooLTag.hpp"

#include "../Pooling/PoolableObject.hpp"

namespace models {
    class Enemy : public GameObject {
        private:
            EnemyType EType;
            int nHealth;
            float fSpeed;

        public:
            Enemy(std::string strName, AnimatedTexture* pTexture, EnemyType EType, float fX, float fY);
            ~Enemy();

        public:
            void initialize();
            //PoolableObject* clone();
        
    };
}

#endif