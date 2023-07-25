#ifndef SCENES_GAME_SPACE_HPP
#define SCENES_GAME_SPACE_HPP

#include "../Scene.hpp"

#include "../../Config/Settings.hpp"

#include "../../Controller/Singleton/TextureManager.hpp"

#include "../Enum/EnumAssetType.hpp"
#include "../Enum/EnumSceneTag.hpp"

#include "../AnimatedTexture.hpp"

#include "../Entity/Background.hpp"
#include "../Entity/Crosshair.hpp"

#include "../../View/Screen/PlayerUI.hpp"

namespace scenes {
    using namespace models;
    class GameSpace : public Scene {
        public:
            GameSpace();
            ~GameSpace();

        public:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();

        private:
            void createBackground(std::string strName, AssetType EType);
            void createUserInterface();
            void createCrosshair();
    };
}

#endif