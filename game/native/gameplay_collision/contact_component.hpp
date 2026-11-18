#pragma once
#include "hit_regions.hpp"
namespace reo::native::gameplay_collision::delivery {
struct Identity {
    std::uint8_t category{255}, token{255};
    friend bool operator==(const Identity&, const Identity&) = default;
};
// Supplemental canonical contact data. Existing HitActor fields own damage,
// progression, pending/response/source bytes and reaction kind (response_class).
// Actor.normalized_marker owns the source cooldown byte32; it is not repeated.
struct Component {
    hit_regions::Regions regions;
    actors::EntityId related;                            // source relationship28
    actors::EntityId recorded_source, recorded_related;  // 11C / 144
    Vec3 point, direction;                               // 120 / 12C
    Identity recipient, related_recipient;               // 117..11A
    Identity source_related;                             // 14A..14B
    std::uint8_t serial{}, priority{};                   // 116 / 13C
    std::uint8_t authored_id{};                          // numeric contact identity6
    std::uint8_t response_code{}, template_kind{};       // 141 / 142
    std::uint8_t auxiliary_a{}, auxiliary_b{}, region{}; // 14C / 14D / 13E
    float probability_bonus{}, damage_scale{1};          // BB0 / BC4
};
} // namespace reo::native::gameplay_collision::delivery
