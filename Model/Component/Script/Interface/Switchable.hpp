#ifndef INTERFACES_SWITCHABLE_HPP
#define INTERFACES_SWITCHABLE_HPP

namespace interfaces {
    using namespace models;

    class Switchable {
        public:
            ~Switchable() {}

        public:
            virtual void switchLeftView() = 0;
            virtual void switchFrontView() = 0;
    };
}

#endif