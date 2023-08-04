#ifndef MODELS_BLOCKER_HPP
#define MODELS_BLOCKER_HPP

#include "../../../Config/Settings.hpp"

#include "../../Enum/EnumBlockerType.hpp"
#include "../../Enum/EnumHitboxType.hpp"
#include "../../Enum/EnumPoolTag.hpp"

#include "../../Entity/Hitbox.hpp"
#include "../../Entity/Hitbox/CircleHitbox.hpp"
#include "../../Entity/Hitbox/RectangleHitbox.hpp"
#include "../../Entity/Hitbox/TriangleHitbox.hpp"

#include "../../Component/Script/Mover.hpp"
#include "../../Component/Script/DirectionSwap.hpp"

#include "../../Component/Script/Interface/Movable.hpp"

#include "../PoolableObject.hpp"

#include "../../../Controller/Singleton/BlockerManager.hpp"

namespace models {
    using namespace controllers;
    using namespace systems;
    class Blocker : public PoolableObject, public Movable {
        private:
            Mover* pMover;
            DirectionSwap* pDirectionSwap;

            Renderer* pSpriteRenderer;
            Renderer* pHitboxRenderer;

            BlockerType EType;
            HitboxType EHitbox;
            sf::Color CColor;
            sf::RectangleShape* pRectangle;
            //sf::Shape* pHitbox;
            Hitbox* pHitbox;

            float fSpeed;

        public:
            Blocker(PoolTag ETag, std::string strName, AnimatedTexture* pTexture, BlockerType EType, HitboxType EHitbox);
            ~Blocker();

        public:
            void initialize();
            void onActivate();
            void onRelease();
            PoolableObject* clone();

        public:
            void move(float fTicks, sf::Time tDeltaTime);
            bool contains(sf::Vector2f vecLocation);

        private:
            void randomizePosition();
            //void initializeHitbox();
        
    };
}

#endif