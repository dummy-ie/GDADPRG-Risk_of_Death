#ifndef VIEWS_TEXT_HPP
#define VIEWS_TEXT_HPP

#include "../Model/GameObject.hpp"
#include "../Model/Component/Renderer/Renderer.hpp"

namespace views {
    using namespace components;
    using namespace models;

    class Text : public GameObject {
        private:
            sf::Text* pText;
            
        public:
            Text(std::string strName, std::string strText, sf::Font* pFont, int nSize = 24);

        public:
            void initialize();
        
        public:
            sf::Text* getText();
            void setText(std::string strText, bool bUpdateOrigin = false);
            void setColor(sf::Color CColor);

        public:
            virtual void setPosition(sf::Vector2f vecPosition);
            virtual sf::FloatRect getGlobalBounds();
    };
}

#endif