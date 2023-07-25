#ifndef INTERFACES_EVENT_LISTENER_HPP
#define INTERFACES_EVENT_LISTENER_HPP

#include "../../../Model/Enum/EnumEventKey.hpp"

namespace interfaces {
    using namespace models;

    /**
     * @brief This is the interface to be extended by classes
     * that wish to be compatible with [EventBroadcaster].
     */
    class EventListener {
        public:
            virtual ~EventListener() {}

        public:
            /**
             * @brief The function that gets invoked whenever an event of a given
             * [EventKey] type is broadcasted.
             * @param mapParameter A HashMap of key-value pairs, where the keys are
             * arbirary string values, and the values are any pointer-type (i.e. void*).
             */
            virtual void onEventTrigger(std::unordered_map<std::string, void*> mapParameter) = 0;
            /**
             * @brief Getter for [EventListener]'s [EventKey]. This assumes that
             * classes implementing this interface have an [EventKey] field, which
             * is the same key of the events that they are expected to listen to.
             * @return EventKey 
             */
            virtual EventKey getKey() = 0;
    };
}

#endif