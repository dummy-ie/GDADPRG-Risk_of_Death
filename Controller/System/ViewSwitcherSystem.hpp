#ifndef SYSTEMS_VIEW_SWITCHER_SYSTEM_HPP
#define SYSTEMS_VIEW_SWITCHER_SYSTEM_HPP

#include "../../Model/Pooling/PoolableObject.hpp"

#include "../../Model/Component/Script/Switcher.hpp"

#include "../../Model/Component/Component.hpp"
#include "../../Model/Component/Input/CrosshairMouseInput.hpp"


#include "../../Model/Entity/Crosshair.hpp"
#include "../../Model/GameObject.hpp"

#include "../Singleton/ObjectPoolManager.hpp"

namespace systems {
    using namespace components;
    using namespace controllers;
    using namespace models;

    class ViewSwitcherSystem : public Component {
        private:
            bool bFront = true;
            bool bSort = false;
            std::vector<Switcher*> vecSwitcher;

        public:
            void switchLeftView();
            void switchFrontView();

            void perform();
            void registerComponent(Switcher* pSwitcher);
            void unregisterComponent(Switcher* pSwitcher);

        /* * * * * * * * * * * * * * * * * * * * * 
        *       SINGLETON-RELATED CONTENT       * 
        * * * * * * * * * * * * * * * * * * * * */

        private:
            static ViewSwitcherSystem* P_SHARED_INSTANCE;

        private:
            ViewSwitcherSystem(std::string strName);
            ViewSwitcherSystem(const ViewSwitcherSystem&);
            ViewSwitcherSystem& operator = (const ViewSwitcherSystem&);

        public:
            static ViewSwitcherSystem* getInstance();
            static void initialize(std::string strName, GameObject* pParent);
    };
}

#endif