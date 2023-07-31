#ifndef ENUM_ITEM_TYPE_HPP
#define ENUM_ITEM_TYPE_HPP

/**
 * @brief An [enum] that declares all possible [EventKeys]
 * used by the [EventBroadcaster]. You may add [EventKey]
 * values as you see fit.
 */
enum class ItemType : int {
    PWR_HEALTH = 0,
    PWR_DAMAGE,
    PWR_PIERCE,
    PWR_INVINCIBILITY,
    PWR_FREEZE
};

#endif

