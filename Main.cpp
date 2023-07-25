#include "iostream"
#include "string"
#include "unordered_map"
#include "vector"

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "Model/AnimatedTexture.cpp"
#include "Model/EmptyGameObject.hpp"
#include "Model/GameObject.cpp"
#include "Model/Scene.cpp"

#include "Model/Component/Component.cpp"

#include "Model/Component/Input/ButtonInput.cpp"
#include "Model/Component/Input/CrosshairMouseInput.cpp"
#include "Model/Component/Input/CrosshairMovement.cpp"
#include "Model/Component/Input/GeneralInput.cpp"
#include "Model/Component/Input/PlayerInput.cpp"

#include "Model/Component/Physics/Collider.cpp"

#include "Model/Component/Renderer/Renderer.cpp"

#include "Model/Component/Script/PlayerControls.cpp"

#include "Model/Entity/Background.cpp"
#include "Model/Entity/Crosshair.cpp"

#include "Model/Pooling/PoolableObject.cpp"

#include "Model/Scene/GameMenu.cpp"
#include "Model/Scene/GameSpace.cpp"

#include "View/Button.cpp"
#include "View/Image.cpp"
#include "View/Text.cpp"
#include "View/View.cpp"

#include "View/Screen/PlayerUI.cpp"
#include "View/Screen/TitleScreen.cpp"

#include "Controller/Singleton/GameObjectManager.cpp"
#include "Controller/Singleton/BlockerManager.cpp"
#include "Controller/Singleton/EnemyManager.cpp"
#include "Controller/Singleton/FontManager.cpp"
#include "Controller/Singleton/ItemManager.cpp"
#include "Controller/Singleton/ObjectPoolManager.cpp"
#include "Controller/Singleton/SFXManager.cpp"
#include "Controller/Singleton/TextureManager.cpp"

#include "Controller/Pooling/GameObjectPool.cpp"

#include "Controller/System/PhysicsManager.cpp"
#include "Controller/System/SceneManager.cpp"
#include "Controller/System/ViewManager.cpp"
#include "Controller/System/EventBroadcaster.cpp"

#include "Controller/Game.cpp"

using namespace controllers;

int main() {
    Game CGame;
    CGame.run();

    return 0;
}