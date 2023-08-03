#include "WindowManager.hpp"

using namespace controllers;

WindowManager *WindowManager::P_SHARED_INSTANCE = NULL;

void WindowManager::setWindow(sf::RenderWindow *rwWindow)
{
    this->rwWindow = rwWindow;
}

sf::RenderWindow *WindowManager::getWindow()
{
    return this->rwWindow;
}

std::vector<sf::View> *WindowManager::getPartitions()
{
    return &(this->vecPartitions);
}

void WindowManager::switchSubscreen(int nSubscreenIndex)
{
    if (this->vecPartitions.empty() || nSubscreenIndex > this->vecPartitions.size())
    {
        std::cout << "[switchSubscreen()]: Invalid index!" << std::endl;
        return;
    }

    if (!this->rwWindow)
    {
        std::cout << "[switchSubscreen()]: rwWindow does not exist!" << std::endl;
        return;
    }

    this->rwWindow->setView(this->vecPartitions.at(nSubscreenIndex));
}

void WindowManager::mouseOverSubscreen(sf::Vector2f mousePosition)
{
    for (auto &&partition : this->vecPartitions)
    {
        if (partition.getViewport().contains(mousePosition))
        {
            this->rwWindow->setView(partition);
            return;
        }
    }
}

void WindowManager::generatePartitions(int nRow, int nCol)
{
    if (!this->rwWindow)
    {
        std::cout << "[generatePartitions()]: rwWindow does not exist! " << std::endl;
        return;
    }

    for (size_t i = 0; i < nRow; i++)
    {
        for (size_t j = 0; j < nCol; j++)
        {
            this->vecPartitions.push_back(sf::View(sf::Vector2f((SCREEN_WIDTH / ((nRow * nCol) / 2)) * i, (SCREEN_HEIGHT / ((nRow * nCol) / 2)) * j), // view center
                                                   sf::Vector2f((SCREEN_WIDTH / nRow * nCol) * i, (SCREEN_HEIGHT / nRow * nCol) * j))); // view size 
        }
    }
}

void WindowManager::generatePartitions(sf::Vector2i partitions)
{
    generatePartitions(partitions.x, partitions.y);
}

WindowManager::WindowManager() {}
WindowManager::WindowManager(const WindowManager &) {}

WindowManager *WindowManager::getInstance()
{
    if (P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new WindowManager();

    return P_SHARED_INSTANCE;
}