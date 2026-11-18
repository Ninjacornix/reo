#pragma once
#include <cstdint>
namespace reo::native::gameplay_actors {
// Portable gameplay reference, distinct from a World-local EntityId capability.
// Resolution always uses the receiving World's canonical primary/auxiliary owner.
struct ActorReference {
    enum class Kind {primary,auxiliary};
    Kind kind{Kind::primary};std::uint16_t identifier{};
    friend bool operator==(const ActorReference&,const ActorReference&)=default;
};
}
