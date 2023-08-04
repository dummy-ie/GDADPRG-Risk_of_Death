#ifndef VIEWS_GAME_SPACE_UI_HPP
#define VIEWS_GAME_SPACE_UI_HPP

#include "../../../Model/Component/Script/Interface/Timeable.hpp"
#include "../../../Model/Component/Script/Timer.hpp"

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
    class GameSpaceUI : public View, public Timeable {
        private:
            // GameTimer* pGameTimer;
            Timer* pTimer;
            float fTime = 0.f;
            std::vector<Text*> vecTime;

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

            Text* copyText(Text* pReference, std::string strText, float fScale);
            void setTime(float fSeconds);


        //public: 
        //    void onEventTrigger(std::unordered_map<std::string, void*> mapParameter);
        //    EventKey getKey();
    };
}

#endif