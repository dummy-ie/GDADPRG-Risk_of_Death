#include "iostream"
#include "string"
#include "unordered_map"
#include "vector"

#include "SFML/Graphics.hpp"

#include "Model/AnimatedTexture.cpp"
#include "Model/EmptyGameObject.hpp"
#include "Model/GameObject.cpp"
#include "Model/Scene.cpp"

#include "Model/Component/Component.cpp"

#include "Model/Component/Input/GeneralInput.cpp"

#include "Model/Component/Renderer/Renderer.cpp"

#include "Model/Pooling/PoolableObject.cpp"

#include "Controller/Game.cpp"

#include "Controller/Singleton/GameObjectManager.cpp"
#include "Controller/Singleton/BlockerManager.cpp"
#include "Controller/Singleton/EnemyManager.cpp"
#include "Controller/Singleton/ItemManager.cpp"
#include "Controller/Singleton/ObjectPoolManager.cpp"
#include "Controller/Singleton/TextureManager.cpp"

#include "Controller/Pooling/GameObjectPool.cpp"

#include "Controller/System/SceneManager.cpp"
#include "Controller/System/ViewManager.cpp"

using namespace controllers;

int main() {
    Game CGame;
    CGame.run();

    return 0;
}