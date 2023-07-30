#include "WindowManager.hpp"

using namespace controllers;

WindowManager* WindowManager::P_SHARED_INSTANCE = NULL;

void WindowManager::setWindow(sf::RenderWindow *rwWindow)
{
    this->rwWindow = rwWindow;
}

sf::RenderWindow *WindowManager::getWindow()
{
    return this->rwWindow;
}

WindowManager::WindowManager() {}
WindowManager::WindowManager(const WindowManager&) {}

WindowManager* WindowManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new WindowManager();

    return P_SHARED_INSTANCE;
}