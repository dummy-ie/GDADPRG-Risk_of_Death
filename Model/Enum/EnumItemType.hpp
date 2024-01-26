#ifndef ENUM_ITEM_TYPE_HPP
#define ENUM_ITEM_TYPE_HPP

enum class ItemType : int {
    NONE = -1,
    
    PWR_HEALTH,     //active
    PWR_DAMAGE,         //acquire
    PWR_PIERCE,         //acquire
    PWR_INVINCIBILITY,  //active
    PWR_FREEZE,          //acquire
    PWR_REVIVE
};

#endif

