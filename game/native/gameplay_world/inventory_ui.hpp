#pragma once
#include "recovery_ui.hpp"
#include <array>
#include <cstdint>
#include <optional>
namespace reo::native::gameplay_application {class NativeSession;}
namespace reo::native::gameplay_world {
class World;
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
    bool request_mode_ready(std::uint32_t)const noexcept;
    InventoryUiStatus configure_requests(std::uint32_t)noexcept; //63 nonzero→604300
    std::optional<std::uint8_t> request_blocked()const noexcept{return request_blocked_;}
    const std::optional<InventoryUiState>& snapshot()const noexcept{return state_;}
private:
    explicit InventoryUi(World&)noexcept;
    World& world_;
    std::optional<InventoryUiState> state_;
    std::optional<std::uint8_t> request_blocked_; //4BAE8D;6DEC80 leaves it untouched
    friend class gameplay_application::NativeSession;
};
}
