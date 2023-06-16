#include "iostream"
#include "string"
#include "unordered_map"
#include "vector"

#include "SFML/Graphics.hpp"

#include "Controller/Game.cpp"

#include "Controller/Singleton/BlockerManager.cpp"
#include "Controller/Singleton/EnemyManager.cpp"
#include "Controller/Singleton/GameObjectManager.cpp"
#include "Controller/Singleton/ItemManager.cpp"
#include "Controller/Singleton/TextureManager.cpp"
#include "Controller/Singleton/ViewManager.cpp"

#include "Model/AnimatedTexture.cpp"
#include "Model/GameObject.cpp"

#include "Model/Component/Component.cpp"

#include "Model/Component/Input/GeneralInput.cpp"

#include "Model/Component/Renderer/Renderer.cpp"

using namespace controllers;

int main() {
    Game CGame;
    CGame.run();

    return 0;
}