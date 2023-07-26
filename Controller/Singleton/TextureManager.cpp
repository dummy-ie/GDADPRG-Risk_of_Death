#include "TextureManager.hpp"

using namespace controllers;

void TextureManager::loadAll() {
    this->loadBackgroundFolder();
    this->loadCrosshairFolder();
    this->loadEnemyFolder();
}

void TextureManager::loadBackgroundFolder() {
    sf::Texture* pTexture = NULL;

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Backgrounds/menu_background.jpg");
    this->mapTexture[AssetType::MENU_BACKGROUND].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Backgrounds/game_background_front.png");
    this->mapTexture[AssetType::GAME_BACKGROUND_FRONT].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Backgrounds/game_background_side.png");
    this->mapTexture[AssetType::GAME_BACKGROUND_SIDE].push_back(pTexture);
}

void TextureManager::loadCrosshairFolder() {
    sf::Texture* pTexture = NULL;

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Crosshairs/crosshair.png");
    this->mapTexture[AssetType::CROSSHAIR].push_back(pTexture);
}

void TextureManager::loadEnemyFolder() {
    int nOffset = 211;
    sf::Texture* pTexture = NULL;

    for (int i = 0; i < 10; i++) {
        int nTemp = static_cast<int>(AssetType::GREEN_SLIME_1) + i;
        AssetType EType = static_cast<AssetType>(nTemp);
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/slimesheet.png", sf::IntRect(0 + (nOffset * i), 0, 212, 159));
        this->mapTexture[EType].push_back(pTexture);
    }

    
}

std::vector<sf::Texture*> TextureManager::getTexture(AssetType EType) {
    return this->mapTexture[EType];
}

sf::Texture* TextureManager::getTextureAt(AssetType EType, int nFrame) {
    if(!this->mapTexture[EType].empty())
        return this->mapTexture[EType][nFrame];
        
    else {
        std::cout << "[ERROR] : No Texture found." << std::endl;
        return NULL;
    }
}

TextureManager* TextureManager::P_SHARED_INSTANCE = NULL;
TextureManager::TextureManager() {}
TextureManager::TextureManager(const TextureManager&) {}

TextureManager* TextureManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new TextureManager();

    return P_SHARED_INSTANCE;
}