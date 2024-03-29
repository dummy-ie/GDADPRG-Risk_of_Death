#include "iostream"
#include "string"
#include "unordered_map"
#include "vector"
#include "cmath"

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "Model/AnimatedTexture.cpp"
#include "Model/EmptyGameObject.cpp"
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

#include "Model/Component/Script/Collectable.cpp"
#include "Model/Component/Script/DirectionSwap.cpp"
#include "Model/Component/Script/PlayerControls.cpp"
#include "Model/Component/Script/Killable.cpp"
#include "Model/Component/Script/Mover.cpp"
#include "Model/Component/Script/Switcher.cpp"
#include "Model/Component/Script/Timer.cpp"
#include "Model/Component/Script/Reloader.cpp"

#include "Model/Entity/Background.cpp"
#include "Model/Entity/Crosshair.cpp"
#include "Model/Entity/Player.cpp"
#include "Model/Entity/Hitbox.cpp"

#include "Model/Entity/Hitbox/CircleHitbox.cpp"
#include "Model/Entity/Hitbox/RectangleHitbox.cpp"
#include "Model/Entity/Hitbox/TriangleHitbox.cpp"

#include "Model/Pooling/PoolableObject.cpp"
#include "Model/Pooling/Enemy/Enemy.cpp"
#include "Model/Pooling/Blocker/Blocker.cpp"
#include "Model/Pooling/Item/Item.cpp"

#include "Model/Scene/GameMenu.cpp"
#include "Model/Scene/GameLeaderboard.cpp"
#include "Model/Scene/GameSelection.cpp"
#include "Model/Scene/GameSpace.cpp"

#include "View/Button.cpp"
#include "View/Image.cpp"
#include "View/Text.cpp"
#include "View/View.cpp"

#include "View/Screen/TitleScreen.cpp"
#include "View/Screen/LeaderboardScreen.cpp"
#include "View/Screen/GameOverScreen.cpp"
#include "View/Screen/SelectionScreen.cpp"
#include "View/Screen/GameSpaceUI/GameSpaceUI.cpp"
#include "View/Screen/GameSpaceUI/Parts/GameTimer.cpp"

#include "Controller/Singleton/GameObjectManager.cpp"
#include "Controller/Singleton/BlockerManager.cpp"
#include "Controller/Singleton/EnemyManager.cpp"
#include "Controller/Singleton/FontManager.cpp"
#include "Controller/Singleton/ItemManager.cpp"
#include "Controller/Singleton/ObjectPoolManager.cpp"
#include "Controller/Singleton/SFXManager.cpp"
#include "Controller/Singleton/TextureManager.cpp"
#include "Controller/Singleton/WindowManager.cpp"

#include "Controller/Pooling/GameObjectPool.cpp"
#include "Controller/Pooling/Component/Director/EnemyDirector.cpp"

#include "Controller/System/ItemCollectorSystem.cpp"
#include "Controller/System/PhysicsManager.cpp"
#include "Controller/System/PoolableKillerSystem.cpp"
#include "Controller/System/ViewSwitcherSystem.cpp"
#include "Controller/System/PowerUpSystem.cpp"
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