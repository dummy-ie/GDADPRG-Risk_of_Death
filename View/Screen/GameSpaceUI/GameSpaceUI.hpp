#ifndef VIEWS_GAME_SPACE_UI_HPP
#define VIEWS_GAME_SPACE_UI_HPP

#include "../../View.hpp"
#include "../../Text.hpp"
#include "../../Button.hpp"

#include "../../Interface/ButtonListener.hpp"

#include "../../../Model/Component/Input/PlayerInput.hpp"
#include "../../../Model/Component/Script/PlayerControls.hpp"

#include "../../../Model/Enum/EnumFontType.hpp"
#include "../../../Model/Enum/EnumViewTag.hpp"

#include "../../../Controller/Singleton/FontManager.hpp"
#include "../../../Controller/System/ViewManager.hpp"
#include "../../../Controller/System/SceneManager.hpp"

#include "../../../Controller/System/Interface/EventListener.hpp"

namespace views {
    using namespace systems;
    class GameSpaceUI : public View {
        public:
            GameSpaceUI(std::string strName);
            ~GameSpaceUI();

        public:
            void initialize();

        //public: 
        //    void onEventTrigger(std::unordered_map<std::string, void*> mapParameter);
        //    EventKey getKey();
    };
}

#endif