#ifndef CONTROLLERS_ITEM_MANAGER_HPP
#define CONTROLLERS_ITEM_MANAGER_HPP

#include "../../Model/Enum/EnumItemType.hpp"
#include "../../Model/Enum/EnumEventKey.hpp"

namespace controllers {
    class ItemManager {
		private:
			//std::unordered_map<ItemType, int> mapItems;
			int nItems;
			std::unordered_map<int, ItemType> mapItems;
			std::vector<ItemType> vecActiveItems;

        private:
		    static ItemManager* P_SHARED_INSTANCE;

		public:
			void addItem(ItemType EType, bool bActive = false);
			bool useItem(int nIndex);

			std::vector<ItemType> getActiveItems();
			ItemType getItem(int nIndex);

			void clearAll();

	    private:
		    ItemManager();
		    ItemManager(ItemManager const&);
		    ItemManager& operator = (ItemManager const&);

	    public:
		    static ItemManager* getInstance();
    };
}

#endif