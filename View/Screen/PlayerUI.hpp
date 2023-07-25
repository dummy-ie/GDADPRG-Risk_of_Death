#ifndef VIEWS_PLAYER_UI_HPP
#define VIEWS_PLAYER_UI_HPP

#include "../View.hpp"
#include "../Text.hpp"
#include "../Button.hpp"

#include "../Interface/ButtonListener.hpp"

#include "../../Model/Component/Input/PlayerInput.hpp"
#include "../../Model/Component/Script/PlayerControls.hpp"

#include "../../Model/Enum/EnumFontType.hpp"
#include "../../Model/Enum/EnumViewTag.hpp"

#include "../../Controller/Singleton/FontManager.hpp"
#include "../../Controller/System/ViewManager.hpp"
#include "../../Controller/System/SceneManager.hpp"

#include "../../Controller/System/Interface/EventListener.hpp"

namespace views {
    using namespace systems;
    class PlayerUI : public View {
        private:
            int nHealth;
            int nBullets;

        public:
            PlayerUI(std::string strName);
            ~PlayerUI();

        public:
            void initialize();

        public:
            void decrementHealth();
            void decrementBullets();

        //public: 
        //    void onEventTrigger(std::unordered_map<std::string, void*> mapParameter);
        //    EventKey getKey();
    };
}

#endif