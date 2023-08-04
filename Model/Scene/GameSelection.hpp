#ifndef SCENES_GAME_SELECTION_HPP
#define SCENES_GAME_SELECTION_HPP

#include "../Scene.hpp"

#include "../../Config/Settings.hpp"

#include "../../Controller/Singleton/TextureManager.hpp"

#include "../Enum/EnumAssetType.hpp"
#include "../Enum/EnumSceneTag.hpp"

#include "../AnimatedTexture.hpp"

#include "../Entity/Background.hpp"

#include "../../View/Screen/SelectionScreen.hpp"
//#include "../../View/Screen/Leaderboards.hpp"

namespace scenes {
    using namespace models;
    using namespace views;
    class GameSelection : public Scene {
        public:
            GameSelection();
            ~GameSelection();

        public:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();
            void onUnloadObjects();

        private:
            void createUserInterface();
            void createBackground();
    };
}

#endif