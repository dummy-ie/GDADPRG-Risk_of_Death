#ifndef CONTROLLERS_GAME_OBJECT_MANAGER_HPP
#define CONTROLLERS_GAME_OBJECT_MANAGER_HPP

namespace controllers {
    class GameObjectManager {
        private:
		    static GameObjectManager* P_SHARED_INSTANCE;

	    private:
		    GameObjectManager();
		    GameObjectManager(GameObjectManager const&);
		    GameObjectManager& operator = (GameObjectManager const&);

	    public:
		    static GameObjectManager* getInstance();
    };
}

#endif