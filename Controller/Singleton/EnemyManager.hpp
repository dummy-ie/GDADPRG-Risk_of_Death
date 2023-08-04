#ifndef CONTROLLERS_ENEMY_MANAGER_HPP
#define CONTROLLERS_ENEMY_MANAGER_HPP

#include "../../Model/Enum/EnumEnemyType.hpp"

#include "../../Model/Pooling/Enemy/Enemy.hpp"

namespace controllers {
	using namespace models;
    class EnemyManager {
		private:
			std::unordered_map<EnemyType, std::vector<Enemy*>> mapEnemyType;
			std::vector<Enemy*> vecEnemies;
		
		private:
			void create(PoolTag ETag, std::string strName, AssetType ETexture, EnemyType EType, HitboxType EHitbox);

		public:
			void loadAll();
			void addEnemy(Enemy* pEnemy);

		public:
			std::vector<Enemy*> getEnemies();
			std::vector<Enemy*> getAllType(EnemyType EType);
		
        private:
		    static EnemyManager* P_SHARED_INSTANCE;

	    private:
		    EnemyManager();
		    EnemyManager(EnemyManager const&);
		    EnemyManager& operator = (EnemyManager const&);

	    public:
		    static EnemyManager* getInstance();
    };
}

#endif