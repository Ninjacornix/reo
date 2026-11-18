#pragma once
#include "../gameplay_world/behavior.hpp"

namespace reo::native::gameplay_application {
// Binds the qualified 64AE50 request consumer to the canonical actor frame.
// The World outlives this synchronous capability; unsupported request kinds
// remain visible failures, with no fallback to an external control callback.
class SessionControlPreparation final:public gameplay_world::ControlPreparation {
public:
    explicit SessionControlPreparation(gameplay_world::World& world):world_(world){}
    bool prepare_control(gameplay_world::World&,gameplay_world::Actor&)noexcept override;
private:
    gameplay_world::World& world_;
};
}
