#ifndef VIEWS_TITLE_SCREEN_HPP
#define VIEWS_TITLE_SCREEN_HPP

#include "../View.hpp"
#include "../Text.hpp"

#include "../../Model/Enum/EnumFontType.hpp"
#include "../../Model/Enum/EnumViewTag.hpp"

#include "../../Controller/Singleton/FontManager.hpp"
#include "../../Controller/System/ViewManager.hpp"

namespace views {
    using namespace systems;
    class TitleScreen : public View {
        public:
            TitleScreen(std::string strName);
            ~TitleScreen();

        public:
            void initialize();
    };
}

#endif