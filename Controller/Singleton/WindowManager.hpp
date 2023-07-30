#ifndef CONTROLLERS_WINDOW_MANAGER_HPP
#define CONTROLLERS_WINDOW_MANAGER_HPP

namespace controllers {
    class WindowManager {
        private:
			sf::RenderWindow* rwWindow;

	    public:
			void setWindow(sf::RenderWindow* rwWindow); 
			sf::RenderWindow* getWindow(); 


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