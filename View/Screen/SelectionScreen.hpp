#ifndef VIEWS_SELECTION_SCREEN_HPP
#define VIEWS_SELECTION_SCREEN_HPP

#include "../View.hpp"
#include "../Text.hpp"
#include "../Button.hpp"

#include "../Interface/ButtonListener.hpp"

#include "../../Model/Enum/EnumFontType.hpp"
#include "../../Model/Enum/EnumViewTag.hpp"

#include "../../Controller/Singleton/FontManager.hpp"
#include "../../Controller/Singleton/WindowManager.hpp"
#include "../../Controller/System/ViewManager.hpp"
#include "../../Controller/System/SceneManager.hpp"

namespace views {
    using namespace systems;
    class SelectionScreen : public View, public ButtonListener {
        private:
            int nRows;
            int nColumns;
            Text* pRows;
            Text* pColumns;
            
            Text* pStart;
            Text* pExit;

        public:
            SelectionScreen(std::string strName);
            ~SelectionScreen();

        public:
            void initialize();
            
        public:
            void onClick(Button* pButton);
            void onHover(Button* pButton);
            void onRelease(Button* pButton);
            void reset(Button* pButton);
    };
}

#endif