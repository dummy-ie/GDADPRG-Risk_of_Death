#ifndef CONTROLLERS_ENEMY_MANAGER_HPP
#define CONTROLLERS_ENEMY_MANAGER_HPP

namespace controllers {
    class EnemyManager {
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