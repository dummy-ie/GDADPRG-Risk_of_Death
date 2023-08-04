#ifndef CONFIGS_SETTINGS_HPP
#define CONFIGS_SETTINGS_HPP

const int SCREEN_WIDTH  = 1230;
const int SCREEN_HEIGHT = 760;

const float SCREEN_SCALE = 10.0f;

const float FRAME_RATE_LIMIT = 60.0f;

const float GAME_SPEED = 1.0f;

const float MIN_COMMON_ENEMY_SPEED = 0.5f;
const float MIN_UNCOMMON_ENEMY_SPEED = 5.0f;
const float MIN_ELITE_ENEMY_SPEED = 10.0f;

const float MAX_COMMON_ENEMY_SPEED = 2.0f;
const float MAX_UNCOMMON_ENEMY_SPEED = 8.0f;
const float MAX_ELITE_ENEMY_SPEED = 12.5f;

const float COMMON_SPRITE_SIZE = 0.3f;
const float UNCOMMON_SPRITE_SIZE = 0.6f;
const float ELITE_SPRITE_SIZE = 1.0f;

const float COMMON_DROP_RATE = 0.02f;
const float UNCOMMON_DROP_RATE = 0.04f;
const float ELITE_DROP_RATE = 0.06f;

const float PWR_DAMAGE_DURATION = 5.0f;
const float PWR_INVINCIBILITY_DURATION = 5.0f;
const float PWR_FREEZE_DURATION = 5.0f;

const float BLOCKER_SPRITE_SIZE = 0.4f;
const float BLOCKER_SPEED = 35.0f;
const float BLOCKER_LENGTH = 5.0f;
const int BLOCKER_VARIATION = 3;


const bool RENDER_HITBOX = true;
const bool ERROR_LOGGING = false;
const bool SIDE_VIEW_SPRITE_TINT = false;

#endif