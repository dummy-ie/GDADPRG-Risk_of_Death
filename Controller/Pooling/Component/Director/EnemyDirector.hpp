#ifndef DIRECTORS_ENEMY_DIRECTOR_HPP
#define DIRECTORS_ENEMY_DIRECTOR_HPP

#include "../../../../Config/Settings.hpp"

#include "../../../../Model/Enum/EnumAssetType.hpp"
#include "../../../../Model/Enum/EnumComponentType.hpp"
#include "../../../../Model/Enum/EnumPoolTag.hpp"

#include "../../../../Model/Component/Component.hpp"
#include "../../../../Model/Pooling/Enemy/Enemy.hpp"
#include "../../../../Model/AnimatedTexture.hpp"

#include "../../../Singleton/ObjectPoolManager.hpp"
#include "../../../Singleton/TextureManager.hpp"
#include "../../GameObjectPool.hpp"

#include "cstdlib"

namespace directors {
    using namespace controllers;
    using namespace components;

    class EnemyDirector : public Component {
        private:
            float fTicks;
            float fUpdateInterval;
            float fUpdateTicks;

        public:
            EnemyDirector(std::string strName);
            ~EnemyDirector();

        private:
            void createEnemyPool(PoolTag ETag, int nPoolSize, EnemyType EType, AssetType ETexture);
            void spawnWave();
            float randomizePercent(float fMax);

        public:
            void perform();
    };
}

#endif