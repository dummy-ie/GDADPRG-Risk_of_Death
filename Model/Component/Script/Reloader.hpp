#ifndef COMPONENTS_RELOADER_HPP
#define COMPONENTS_RELOADER_HPP

#include "../../Enum/EnumComponentType.hpp"

#include "../Component.hpp"

#include "Interface/Reloadable.hpp"

namespace components {
    using namespace interfaces;
    class Reloader : public Component {
        private:
            Reloadable* pReloadable;
            bool bReloading;

            float fFrameInterval;
            float fTicks;

        public:
            Reloader(std::string strName);

        public:
            void perform();
            void start();
            void stop();

        private:
            void reload();

        public:
            void setReloadable(Reloadable* pReloadable);
            bool isReloading();
    };
}

#endif