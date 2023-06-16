#ifndef CONTROLLERS_BLOCKER_MANAGER_HPP
#define CONTROLLERS_BLOCKER_MANAGER_HPP

namespace controllers {
    class BlockerManager {
        private:
		    static BlockerManager* P_SHARED_INSTANCE;

	    private:
		    BlockerManager();
		    BlockerManager(BlockerManager const&);
		    BlockerManager& operator = (BlockerManager const&);

	    public:
		    static BlockerManager* getInstance();
    };
}

#endif