#ifndef CONTROLLERS_VIEW_MANAGER_HPP
#define CONTROLLERS_VIEW_MANAGER_HPP

namespace controllers {
    class ViewManager {
        private:
		    static ViewManager* P_SHARED_INSTANCE;

	    private:
		    ViewManager();
		    ViewManager(ViewManager const&);
		    ViewManager& operator = (ViewManager const&);

	    public:
		    static ViewManager* getInstance();
    };
}

#endif