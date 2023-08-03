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

bool WindowManager::mouseOverSubscreen(sf::Vector2f mousePosition)
{
    for (auto &partition : this->vecPartitions)
    {
        sf::FloatRect frPartitionDimensions(partition.getCenter() - (partition.getSize() / 2.f), partition.getSize());
        // std::cout << "partition: position " << frPartitionDimensions.left << ", " << frPartitionDimensions.top << " size " << frPartitionDimensions.width << ", " << frPartitionDimensions.height << std::endl;
        // std::cout << "mouse position: " << mousePosition.x << ", " << mousePosition.y << std::endl;
        if (frPartitionDimensions.contains(mousePosition))
        {
            // std::cout << "contains true" << std::endl;
            this->rwWindow->setView(partition);
            return true;
        }
    }

    return false;
}

void WindowManager::generatePartitions(int nCol, int nRow)
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
            float fPartitionWidth = SCREEN_WIDTH / nRow;
            float fPartitionHeight = SCREEN_HEIGHT / nCol;

            // float fHeightRatio = (float)SCREEN_HEIGHT / (float)SCREEN_WIDTH;
            // float fWidthRatio = (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT;

            // if (fPartitionWidth * fHeightRatio <= fPartitionHeight)
            // {
            //     fPartitionHeight = fPartitionWidth * fHeightRatio;
            // }
            // else if (fPartitionHeight * fWidthRatio <= fPartitionWidth)
            // {
            //     fPartitionWidth = fPartitionHeight * fWidthRatio;
            // }

            this->vecPartitions.push_back(sf::View(sf::Vector2f(fPartitionWidth * i + fPartitionWidth / 2.f, fPartitionHeight * j + fPartitionHeight / 2.f), // view center
                                                   sf::Vector2f(fPartitionWidth, fPartitionHeight)));                                                    // view size
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