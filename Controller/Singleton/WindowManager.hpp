#ifndef CONTROLLERS_WINDOW_MANAGER_HPP
#define CONTROLLERS_WINDOW_MANAGER_HPP

#include "../../Config/Settings.hpp"

namespace controllers {
    class WindowManager {
        private:
			sf::RenderWindow* rwWindow;
			std::vector<sf::View> vecPartitions;

	    public:
			void setWindow(sf::RenderWindow* rwWindow); 
			sf::RenderWindow* getWindow(); 
			std::vector<sf::View>* getPartitions(); // incase u want to get the sizes of each view idk

			void switchSubscreen(int nSubscreenIndex);

			bool mouseOverSubscreen(sf::Vector2f mousePosition);

			void generatePartitions(int nRow, int nCol);
			void generatePartitions(sf::Vector2i partitions);


        private:
		    static WindowManager* P_SHARED_INSTANCE;

	    private:
		    WindowManager();
		    WindowManager(WindowManager const&);
		    WindowManager& operator = (WindowManager const&);

	    public:
		    static WindowManager* getInstance();
    };
}

#endif