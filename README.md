# Risk of Death

**Risk of Death** is a 2D multi-perspective endless shooter developed in C++ using SFML. Loosely inspired by *Risk of Rain 2* and *Left 4 Dead 2*, the game challenges players to survive increasingly intense waves of enemies through quick decision-making, smart item usage, and strategic shooting across multiple viewpoints.

## Game Overview

The game features two primary visual perspectives:
- **Front View**: Split into N x M subscreens, where enemies approach. Players can zoom into each partition via First-Person View to aim and shoot.
- **Right Side View**: Displays the full game space, providing depth perception and positional awareness of enemies approaching the front view.

The objective is to survive for as long as possible by shooting down incoming enemies while preventing them from reaching the player's screen. Survival time is recorded in a persistent leaderboard.

## Core Gameplay Features

- **Perspective Switching**: Use `[A]` and `[D]` to toggle between Front View and Right Side View.
- **First-Person Shooting**: Zoom into any subscreen of the Front View to aim and shoot using the mouse.
- **Reload Mechanic**: Fire a limited number of shots based on screen partitions, with reloading triggered by `[R]`.
- **Inventory System**: Three-slot hotkey inventory (`[1]`, `[2]`, `[3]`) to store and activate acquired items.
- **Dynamic Scaling and Rendering**: Enemy sizes and render order adjust based on distance from the player (visible in Right Side View).

## Entities

### Enemies
Three enemy types:
- **Common**: Low health, small, low speed
- **Uncommon**: Medium health and speed
- **Elite**: High health, large, fast

Enemy speed increases over time based on a configurable speed scale, and spawn rates decay to introduce stronger enemy types as the game progresses.

### Items
- **Health Boost**: Heals 1–3 HP on pickup
- **Damage Boost**: Temporarily doubles damage
- **Piercing Shot**: Next shot penetrates all enemies in a line
- **Custom Items**: At least two additional unique items implemented

Items are either **activated** instantly or **acquired** for later use via the hotkey inventory.

### Blockers
Block line-of-sight and shots. Types include:
- Mobile Blockers
- Immobile (UP–DOWN and LEFT–RIGHT) Blockers

## Screens and UI

- **Title Screen**: Start game, view leaderboard, or exit
- **Game Proper**:
  - Front View (with optional First-Person View)
  - Right Side View
- **Leaderboards**: Records top 5 survival times (saved to text or binary file)

## Technical Features

- **Engine**: SFML
- **Architecture**: Entity-Component System and MVC
- **Managers**:
  - `GameObjectManager`
  - `TextureManager`
  - `EnemyManager`
  - `ItemManager`
  - `BlockerManager`
- **Hitbox System**: Uses rectangular, circular, and triangular hitboxes depending on the entity
- **Game Speed Control**: Adjustable from paused (0.0) to normal (1.0), affects all entities

## Bonus and Extensibility

Bonus features may include advanced mechanics that enhance gameplay, provided they don’t compromise the base specifications. These are integrated cleanly into the existing architecture and can be toggled or disabled for testing base functionality.

## Development

- **Language**: C++
- **Library**: SFML (Simple and Fast Multimedia Library)
- **Design Patterns**: Modular, manager-based design with strong separation of concerns

## Leaderboards

Leaderboard times are saved and displayed in MM:SS or HH:MM:SS format. Entries are auto-updated and persist across sessions.
