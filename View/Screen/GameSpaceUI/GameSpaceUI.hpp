#ifndef VIEWS_GAME_SPACE_UI_HPP
#define VIEWS_GAME_SPACE_UI_HPP

#include "../../View.hpp"
#include "../../Text.hpp"
#include "../../Button.hpp"

#include "Parts/GameTimer.hpp"

#include "../../Interface/ButtonListener.hpp"

#include "../../../Model/Enum/EnumFontType.hpp"
#include "../../../Model/Enum/EnumViewTag.hpp"

#include "../../../Controller/Singleton/FontManager.hpp"
#include "../../../Controller/System/ViewManager.hpp"
#include "../../../Controller/System/SceneManager.hpp"

#include "../../../Controller/System/Interface/EventListener.hpp"

namespace views {
    using namespace systems;
    class GameSpaceUI : public View {
        private:
            GameTimer* pGameTimer;

            Image* pHeart;
            Image* pBullet;

            Text* pHealth;
            Text* pBullets;
        public:
            GameSpaceUI(std::string strName);
            ~GameSpaceUI();

        public:
            void initialize();
            void update();
        //public: 
        //    void onEventTrigger(std::unordered_map<std::string, void*> mapParameter);
        //    EventKey getKey();
    };
}

#endif