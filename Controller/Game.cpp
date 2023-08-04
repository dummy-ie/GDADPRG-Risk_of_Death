#include "Game.hpp"

using namespace controllers;

Game::Game() : rwWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Risk of Death", sf::Style::Titlebar | sf::Style::Close) {
    this->rwWindow.setFramerateLimit(FRAME_RATE_LIMIT);

    WindowManager::getInstance()->setWindow(&this->rwWindow);
    //WindowManager::getInstance()->generatePartitions(sf::Vector2i(2, 3));
    FontManager::getInstance()->loadAll();
    SFXManager::getInstance()->loadAll();

    
    SceneManager::getInstance()->registerScene(new GameMenu());
    SceneManager::getInstance()->registerScene(new GameSelection());
    SceneManager::getInstance()->registerScene(new GameLeaderboard());
    SceneManager::getInstance()->registerScene(new GameSpace());

    SceneManager::getInstance()->loadScene(SceneTag::GAME_MENU);
}

void Game::run() {
    sf::Clock CClock = sf::Clock();
    sf::Time tLastUpdate = sf::Time::Zero;
    sf::Time tTimePerFrame = sf::seconds(1.0f / FRAME_RATE_LIMIT);
    while(this->rwWindow.isOpen()) {
        this->processEvents();
        tLastUpdate += CClock.restart();
        while(tLastUpdate > tTimePerFrame) {
            tLastUpdate -= tTimePerFrame;
            this->update(tTimePerFrame);
        }
        SceneManager::getInstance()->checkLoadScene();
        // Temporary
        if (SceneManager::getInstance()->isLoaded(SceneTag::GAME_SPACE))
            this->rwWindow.setMouseCursorVisible(false);
        else
            this->rwWindow.setMouseCursorVisible(true);
        this->render();
    }
}

void Game::processEvents() {
    sf::Event eEvent;

    while(this->rwWindow.pollEvent(eEvent)) {
        switch(eEvent.type) {
            case sf::Event::Closed:
                this->rwWindow.close();
                break;
  
            default:
                GameObjectManager::getInstance()->processInput(eEvent);
                break;
        }
    }
}

void Game::update(sf::Time tDeltaTime) {
    GameObjectManager::getInstance()->update(tDeltaTime);
}

void Game::render() {
    this->rwWindow.clear();
    GameObjectManager::getInstance()->draw(&this->rwWindow);
    this->rwWindow.display();
}