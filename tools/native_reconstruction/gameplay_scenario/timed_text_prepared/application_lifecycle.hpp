#pragma once
#include <cstdint>
#include <optional>
namespace reo::native::gameplay_session {
// Native application transitions own the observable text-display gate. This
// replaces MAIN-group identity bookkeeping, rather than storing guest fields.
// Construction establishes no application phase or successful UI capability.
class ApplicationLifecycle final {
public:
    enum class Phase {unbound,preparing,gameplay,frontend,closed};
    Phase phase()const noexcept{return phase_;}
    bool begin_preparation()noexcept{
        if(phase_!=Phase::unbound)return false;phase_=Phase::preparing;return true;
    }
    bool enter_gameplay()noexcept{
        if(phase_!=Phase::preparing&&phase_!=Phase::frontend)return false;
        phase_=Phase::gameplay;return true;
    }
    bool leave_gameplay()noexcept{
        if(phase_!=Phase::gameplay)return false;phase_=Phase::frontend;return true;
    }
    void close()noexcept{phase_=Phase::closed;}
    //1B4820 only applies6DEE20 during gameplay. Preparing/frontend text uses
    // the original out-of-game branch; unknown/closed lifetimes refuse.
    std::optional<bool> inventory_filter_enabled()const noexcept{
        switch(phase_){
        case Phase::preparing:case Phase::frontend:return false;
        case Phase::gameplay:return true;
        default:return{};
        }
    }
private:
    Phase phase_{Phase::unbound};
};
}
