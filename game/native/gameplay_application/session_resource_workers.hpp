#pragma once
#include "session_resources.hpp"
#include "../gameplay_update/update.hpp"
namespace reo::native::gameplay_application {
// Adopts the actual resource/pose passes at their existing Update positions.
// Every remaining operation retains its explicit owner; none returns success
// merely because this graph cannot implement that worker or phase effect.
class SessionResourceWorkers final:public gameplay_update::PhaseServices {
public:
    SessionResourceWorkers(NativeSession&,SessionResources&,gameplay_update::PhaseServices&);
    void run(gameplay_update::Worker,gameplay_update::Owner&)override;
    bool button(gameplay_update::Button,gameplay_update::Owner&)override;
    bool transition_request(gameplay_update::Owner&)override;
    void effect(gameplay_update::PhaseEffect,gameplay_update::Owner&,std::uint32_t=0)override;
private:
    NativeSession& session_;SessionResources& resources_;gameplay_update::PhaseServices& remaining_;
    void verify(gameplay_update::Owner&)const;
};
}
