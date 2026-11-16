#pragma once
#include "recovery_ui.hpp"
#include <array>
#include <cstdint>
#include <optional>
namespace reo::native::gameplay_application {class NativeSession;}
namespace reo::native::gameplay_scenario {class InventoryUiResources;}
namespace reo::native::gameplay_world {
class World;
struct Actor;
enum class InventoryUiStatus {completed,closed,busy,unavailable_actor,unavailable_phase,unavailable_request_reset};
struct InventoryUiState {
    std::uint8_t phase{}; //75:5EC4; only actual6DEC80 establishes the cold zero.
    std::uint8_t update_enabled{},requests_enabled{}; //4BAE33/4BAE8C
    std::array<std::uint8_t,3> panel_active{}; //75:5B70/5BF0/5A70
    enum class Record {primary,secondary};
    Record selected{Record::primary},auxiliary{Record::secondary}; //native identities, not guest pointers
};
// Sole application-owned inventory UI lifecycle. The admitted source-cleared
// phase executes its real actor/status changes; active presentation refuses.
class InventoryUi final:public RecoveryUi {
public:
    bool bound_to(const World&)const noexcept override;
    bool close_ready()const noexcept;
    bool close()noexcept override; //complete6E1430 closed phase
    InventoryUiStatus initialize()noexcept; //actual6DEC80 typed cold state
    InventoryUiStatus force_close()noexcept; //108→5F4FD0→6E1430
    // Source5F4F00 owner gate and6DEE20 suppression before the ordinary
    // primary action pass. The actor must be a live entity in this World.
    InventoryUiStatus prepare_actor(Actor&)noexcept;
    // Actual6DEE20 result using the canonical UI state and session owner tag.
    std::optional<bool> dialogue_suppressed()const noexcept;
    bool request_mode_ready(std::uint32_t)const noexcept;
    InventoryUiStatus configure_requests(std::uint32_t)noexcept; //63:604300/604310
    // Expected-current identity prevents a foreign graph from replacing or
    // releasing another graph's borrow. Same-owner binding is idempotent.
    InventoryUiStatus bind_resources(gameplay_scenario::InventoryUiResources*,
        const gameplay_scenario::InventoryUiResources* expected_current=nullptr)noexcept;
    const gameplay_scenario::InventoryUiResources* resources()const noexcept{return resources_;}
    std::optional<std::uint8_t> request_blocked()const noexcept{return request_blocked_;}
    InventoryUiStatus reset_request_gate()noexcept; //5D7D60 clears4BAE8D only
    const std::optional<InventoryUiState>& snapshot()const noexcept{return state_;}
private:
    explicit InventoryUi(World&)noexcept;
    World& world_;
    std::optional<InventoryUiState> state_;
    std::optional<std::uint8_t> request_blocked_; //4BAE8D;6DEC80 leaves it untouched
    gameplay_scenario::InventoryUiResources* resources_{};
    friend class gameplay_application::NativeSession;
};
}
