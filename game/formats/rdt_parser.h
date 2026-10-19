#pragma once

#include <cstdint>
#include <vector>
#include <string>

namespace reo {

/*
 * RDT (Room Data) Parser
 *
 * RDT files contain room/level data for RE Outbreak:
 * - Room geometry references
 * - Camera positions and triggers
 * - Collision data
 * - Item placement
 * - Enemy spawn points
 * - Door/transition definitions
 * - In-game scripts (event triggers, puzzle logic)
 * - Multiplayer-specific data (spawn points, objectives)
 *
 * The RDT format is shared across multiple RE games on PS2
 * but Outbreak adds multiplayer extensions.
 */

struct RdtCamera {
    float position[3];
    float target[3];
    float fov;
    uint32_t flags;
};

struct RdtDoor {
    uint32_t target_room;
    float position[3];
    uint32_t flags;
};

struct RdtItem {
    uint16_t item_id;
    uint16_t quantity;
    float position[3];
    float rotation;
    uint32_t flags;
};

struct RdtEnemySpawn {
    uint16_t enemy_type;
    uint16_t count;
    float position[3];
    uint32_t flags;
};

class RdtParser {
  public:
    RdtParser() = default;

    bool parse(const uint8_t* data, uint32_t size);

    const std::vector<RdtCamera>& cameras() const {
        return m_cameras;
    }
    const std::vector<RdtDoor>& doors() const {
        return m_doors;
    }
    const std::vector<RdtItem>& items() const {
        return m_items;
    }
    const std::vector<RdtEnemySpawn>& enemy_spawns() const {
        return m_enemy_spawns;
    }

  private:
    std::vector<RdtCamera> m_cameras;
    std::vector<RdtDoor> m_doors;
    std::vector<RdtItem> m_items;
    std::vector<RdtEnemySpawn> m_enemy_spawns;
};

} // namespace reo
