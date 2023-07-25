#ifndef SYSTEMS_EVENT_BROADCASTER_HPP
#define SYSTEMS_EVENT_BROADCASTER_HPP

#include "../../Controller/System/Interface/EventListener.hpp"
#include "../../Model/Enum/EnumEventKey.hpp"

namespace systems {
    using namespace controllers;
    using namespace models;
    using namespace interfaces;
    /**
     * @brief The Singleton class that keeps track of all [EventListener] objects,
     * and handles the broadcasting of events. It is a Singleton so that ANY class
     * can refer to it whenever they wish to broadcast events of a given [EventType].
     */
    class EventBroadcaster {
        private:
            /**
             * @brief A HashMap of [EventListener] objects, stored based on the
             * [EventKey] that they listen to.
             */
            std::unordered_map<EventKey, std::vector<EventListener*>> mapListener;

            /**
             * @brief A vector version of the HashMap shown above. This is to
             * aid in linear iteration of [EventListeners], whenever needed.
             */
            std::vector<EventListener*> vecListener;
        
        public:
            /**
             * @brief Registers [pListener] to [this.mapListener] and [this.vecListener].
             * This function assumes that [pListener]'s [getKey(...)] function already
             * returns the correct value of [EventKey].
             * @param pListener 
             */
            void registerListener(EventListener* pListener);

            /**
             * @brief Unregisters [pListener] from [this.mapListener] and [this.vecListener].
             * @param pListener 
             */
            void unregisterListener(EventListener* pListener);

            /**
             * @brief Unregisters, and subsequently deletes, all [EventListeners] registered
             * in this class. This is mainly used when switching [Scenes].
             */
            void unregisterAllListeners();

            /**
             * @brief The function that broadcasts an event to ALL [EventListener]'s whose
             * [getKey(...)] function returns a value equal to the [EKey] parameter.
             * 
             * The [mapParameter] HashMap is meant to store a limitless amount of parameters,
             * with unspecified data types. The keys to this map are arbitrarily chosen
             * by the developer.
             * @param EKey 
             * @param mapParameter 
             */
            void broadcast(EventKey EKey, std::unordered_map<std::string, void*> mapParameter = {});

        private:
            /**
             * @brief Utility function that checks if [pListener] exists in [vecListener]. Note that
             * if [vecListener] is left empty, the function finds [pListener] in [this.vecListener]
             * instead.
             * 
             * It returns the index of [pListener] if found, and [-1] if not.
             * @param pListener 
             * @param vecListener 
             * @return int 
             */
            int findListener(EventListener* pListener, std::vector<EventListener*> vecListener = {});

        /* * * * * * * * * * * * * * * * * * * * * 
         *       SINGLETON-RELATED CONTENT       * 
         * * * * * * * * * * * * * * * * * * * * */
        private:
            static EventBroadcaster* P_SHARED_INSTANCE;

        private:
            EventBroadcaster();
            EventBroadcaster(const EventBroadcaster&);
            EventBroadcaster& operator = (const EventBroadcaster&);

        public:
            static EventBroadcaster* getInstance();
        /* * * * * * * * * * * * * * * * * * * * */
    };
}

#endif