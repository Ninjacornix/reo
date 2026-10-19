#include "rdt_parser.h"
#include <cstdio>

namespace reo {

bool RdtParser::parse(const uint8_t* data, uint32_t size) {
    m_cameras.clear();
    m_doors.clear();
    m_items.clear();
    m_enemy_spawns.clear();

    if (size < 16)
        return false;

    // TODO: Parse RDT header and offset table
    // The RDT format has an offset table at the beginning pointing to
    // various data sections (cameras, collision, scripts, items, etc.)

    printf("[RDT] Parsing room data (%u bytes)\n", size);

    return true;
}

} // namespace reo
