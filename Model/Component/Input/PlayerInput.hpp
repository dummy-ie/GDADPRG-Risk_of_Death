#ifndef COMPONENTS_PLAYER_INPUT_HPP
#define COMPONENTS_PLAYER_INPUT_HPP

#include "../../Enum/EnumComponentType.hpp"

#include "GeneralInput.hpp"

namespace components {
    class PlayerInput : public GeneralInput {
        private:
            bool bLeft;
            bool bRight;
            bool bPartition;

        public:
            PlayerInput(std::string strName);

        public:
            void perform();

        private:
            void processKeyInput(bool bPressed);

        public:
            bool isLeft();
            bool isRight();
            bool isPartition();
    };
}

#endif