#ifndef SCENES_GAME_SPACE_HPP
#define SCENES_GAME_SPACE_HPP

#include "../Scene.hpp"

#include "../../Config/Settings.hpp"

#include "../../Controller/Singleton/TextureManager.hpp"
#include "../../Controller/System/PoolableKillerSystem.hpp"
#include "../../Controller/System/PowerUpSystem.hpp"
#include "../../Controller/System/ItemCollectorSystem.hpp"
#include "../../Controller/System/EventBroadcaster.hpp"

#include "../../Controller/System/Interface/EventListener.hpp"

#include "../../Controller/Pooling/Component/Director/EnemyDirector.hpp"

#include "../Enum/EnumAssetType.hpp"
#include "../Enum/EnumSceneTag.hpp"

#include "../AnimatedTexture.hpp"

#include "../EmptyGameObject.hpp"

#include "../Entity/Background.hpp"
#include "../Entity/Crosshair.hpp"
#include "../Entity/Player.hpp"

#include "../Pooling/Enemy/Enemy.hpp"

#include "../../View/Screen/GameSpaceUI/GameSpaceUI.hpp"

namespace scenes {
    using namespace models;
    using namespace directors;
    class GameSpace : public Scene {
        public:
            GameSpace();
            ~GameSpace();

        public:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();
            void onUnloadObjects();

        private:
            void createNullObjectComponents();
            void createBackground();
            void createPlayer();
            void createUserInterface();
            void createCrosshair();
    };
}

#endif