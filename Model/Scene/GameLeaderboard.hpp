#ifndef SCENES_GAME_LEADERBOARD_HPP
#define SCENES_GAME_LEADERBOARD_HPP

#include "../Scene.hpp"

#include "../../Config/Settings.hpp"

#include "../../Controller/Singleton/TextureManager.hpp"

#include "../Enum/EnumAssetType.hpp"
#include "../Enum/EnumSceneTag.hpp"

#include "../AnimatedTexture.hpp"

#include "../Entity/Background.hpp"

// #include "../../View/Screen/TitleScreen.hpp"
#include "../../View/Screen/LeaderboardScreen.hpp"

namespace scenes {
    using namespace models;
    using namespace views;
    class GameLeaderboard : public Scene {
        public:
            GameLeaderboard();
            ~GameLeaderboard();

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