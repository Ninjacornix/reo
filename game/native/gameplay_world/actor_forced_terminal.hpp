#pragma once
#include "actor_recovery.hpp"
#include "../gameplay_scenario/cutscene_requests.hpp"

namespace reo::native::gameplay_world {
// The forced terminal transition shares the actual inventory, message, event,
// UI, and action-pose consumers used by ordinary gameplay.
class ActorForcedTerminal final:public gameplay_scenario::ForcedActorTerminal {
public:
    ActorForcedTerminal(gameplay_update::Owner&,ActorResourceOperations&,RecoveryUi&);
    bool apply(World&,std::uint32_t mode) noexcept override;
    void force(std::uint32_t mode);

private:
    gameplay_update::Owner& update_;
    ActorResourceOperations& operations_;
    RecoveryUi& ui_;
    World& world_;
};
}
