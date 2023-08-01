#ifndef CONTROLLERS_ITEM_MANAGER_HPP
#define CONTROLLERS_ITEM_MANAGER_HPP

#include "../../Model/Enum/EnumItemType.hpp"
#include "../../Model/Enum/EnumEventKey.hpp"

namespace controllers {
    class ItemManager {
        private:
		    static ItemManager* P_SHARED_INSTANCE;
			std::unordered_map<ItemType, int> mapItems;

		public:
			void addItem(ItemType EType);
			bool useItem(ItemType EType);

			int getItemCount(ItemType EType);

			void deleteAllItems();

	    private:
		    ItemManager();
		    ItemManager(ItemManager const&);
		    ItemManager& operator = (ItemManager const&);

	    public:
		    static ItemManager* getInstance();
    };
}

#endif