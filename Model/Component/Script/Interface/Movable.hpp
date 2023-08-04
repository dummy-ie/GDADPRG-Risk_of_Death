#ifndef INTERFACES_MOVABLE_HPP
#define INTERFACES_MOVABLE_HPP

namespace interfaces {
    using namespace models;

    class Movable {
        public:
            ~Movable() {}

        public:
            virtual void move(float fTicks, sf::Time tDeltaTime) = 0;
    };
}

#endif