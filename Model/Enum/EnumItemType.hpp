#ifndef ENUM_ITEM_TYPE_HPP
#define ENUM_ITEM_TYPE_HPP

/**
 * @brief An [enum] that declares all possible [EventKeys]
 * used by the [EventBroadcaster]. You may add [EventKey]
 * values as you see fit.
 */
enum class ItemType : int {
    NONE = -1,
    
    PWR_HEALTH,     //active
    PWR_DAMAGE,         //acquire
    PWR_PIERCE,         //acquire
    PWR_INVINCIBILITY,  //active
    PWR_FREEZE          //acquire
};

#endif

