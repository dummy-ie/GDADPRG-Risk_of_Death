#ifndef INTERFACES_RELOADABLE_HPP
#define INTERFACES_RELOADABLE_HPP

namespace interfaces {
    using namespace models;

    class Reloadable {
        public:
            ~Reloadable() {}

        public:
            virtual void reload() = 0;
    };
}

#endif