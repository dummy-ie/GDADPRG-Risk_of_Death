#ifndef COMPONENTS_PLAYER_INPUT_HPP
#define COMPONENTS_PLAYER_INPUT_HPP

#include "../../Enum/EnumComponentType.hpp"

#include "GeneralInput.hpp"

namespace components {
    class PlayerInput : public GeneralInput {
        private:
            bool bLeft;
            bool bRight;
            bool b1;
            bool b2;
            bool b3;
            bool bZoomOut;
            bool bR;

        public:
            PlayerInput(std::string strName);

        public:
            void perform();

        private:
            void processKeyInput(bool bPressed);

        public:
            bool isLeft();
            bool isRight();
            bool is1();
            bool is2();
            bool is3();
            bool isPartition();
            bool isZoomOut();
            bool isR();
    };
}

#endif