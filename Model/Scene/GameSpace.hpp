#ifndef SCENES_GAME_SPACE_HPP
#define SCENES_GAME_SPACE_HPP

#include "../Scene.hpp"

#include "../../Config/Settings.hpp"

#include "../../Controller/Singleton/TextureManager.hpp"

#include "../../Controller/Pooling/Component/Director/EnemyDirector.hpp"

#include "../Enum/EnumAssetType.hpp"
#include "../Enum/EnumSceneTag.hpp"

#include "../AnimatedTexture.hpp"

#include "../EmptyGameObject.hpp"

#include "../Entity/Background.hpp"
#include "../Entity/Crosshair.hpp"
#include "../Pooling/Enemy/Enemy.hpp"

#include "../../View/Screen/PlayerUI.hpp"

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

        private:
            void createNullObjectComponents();
            void createBackground(std::string strName, AssetType EType);
            void createUserInterface();
            void createCrosshair();
    };
}

#endif