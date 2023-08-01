#ifndef ENUM_EVENT_KEY_HPP
#define ENUM_EVENT_KEY_HPP

/**
 * @brief An [enum] that declares all possible [EventKeys]
 * used by the [EventBroadcaster]. You may add [EventKey]
 * values as you see fit.
 */
enum class EventKey : int {
    PWR_HEALTH = 0,
    PWR_DAMAGE,
    PWR_PIERCE,
    PWR_INVINCIBILITY,
    PWR_FREEZE
};

#endif

