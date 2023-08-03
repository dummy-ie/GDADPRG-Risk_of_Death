#ifndef CONTROLLERS_ENEMY_MANAGER_HPP
#define CONTROLLERS_ENEMY_MANAGER_HPP

#include "../../Model/Pooling/Enemy/Enemy.hpp"

namespace controllers {
	using namespace models;
    class EnemyManager {
		private:
			std::unordered_map<EnemyType EType, std::vector<Enemy*>> mapEnemyType;
			std::vector<Enemy*> vecEnemies;
		
		private:
			void create(EnemyType EType, std::string strName);

		public:
			void addEnemy(Enemy* pEnemy);
			void switchView();
		
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