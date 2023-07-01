#include "ViewManager.hpp"

using namespace systems;

ViewManager* ViewManager::P_SHARED_INSTANCE = NULL;
ViewManager::ViewManager() {}
ViewManager::ViewManager(const ViewManager&) {}

ViewManager* ViewManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new ViewManager();

    return P_SHARED_INSTANCE;
}