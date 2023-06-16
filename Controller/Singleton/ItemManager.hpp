#ifndef CONTROLLERS_ITEM_MANAGER_HPP
#define CONTROLLERS_ITEM_MANAGER_HPP

namespace controllers {
    class ItemManager {
        private:
		    static ItemManager* P_SHARED_INSTANCE;

	    private:
		    ItemManager();
		    ItemManager(ItemManager const&);
		    ItemManager& operator = (ItemManager const&);

	    public:
		    static ItemManager* getInstance();
    };
}

#endif