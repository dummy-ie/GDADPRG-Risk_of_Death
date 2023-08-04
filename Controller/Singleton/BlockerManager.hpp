#ifndef CONTROLLERS_BLOCKER_MANAGER_HPP
#define CONTROLLERS_BLOCKER_MANAGER_HPP

#include "../../Model/Pooling/PoolableObject.hpp"

namespace controllers {
    class BlockerManager {
		private:
			//poolableobject because crunch and circular dependency
			std::vector<PoolableObject*> vecBlocker;
		
		public:
			void addBlocker(PoolableObject* pBlocker);
            void deleteBlocker(PoolableObject* pBlocker);
            void deleteAllBlockers();

			std::vector<PoolableObject*> getBlockers();

			void clearAll();

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