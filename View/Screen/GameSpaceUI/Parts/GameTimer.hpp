#ifndef VIEWS_GAME_TIMER_HPP
#define VIEWS_GAME_TIMER_HPP

#include <iomanip>
#include <sstream>

#include "../../../View.hpp"

#include "../../../Text.hpp"

#include "../../../../Controller/Singleton/FontManager.hpp"

namespace views {
    using namespace controllers;
    class GameTimer : public View {
        private:
            std::vector<Text*> vecTime;

        public:
            GameTimer(std::string strName);
            ~GameTimer();
            
        public:
            void initialize();

        public:
            void setTime(float fSeconds);

        private:
            void createTimer();
            Text* copyText(Text* pReference, std::string strText, float fScale);
    };
}

#endif