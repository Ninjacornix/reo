#pragma once
#include "native_session.hpp"
#include "../gameplay_world/primary_actor_records.hpp"
#include "../gameplay_world/primary_roster_startup.hpp"
namespace reo::native::gameplay_application {
// Asset/model startup capabilities for one existing canonical application.
// NativeSession must outlive this owner. The supplied bank publication comes
// from its actual producer; cold1B2150 does not establish the default-load gate.
class SessionStartup final {
public:
    SessionStartup(NativeSession&,std::shared_ptr<const reo::assets::Source>,
                   std::shared_ptr<const gameplay_world::HumanoidMotionBanks>);
    ~SessionStartup();
    SessionStartup(const SessionStartup&)=delete;
    SessionStartup& operator=(const SessionStartup&)=delete;
    gameplay_world::PrimaryRecordsInitialized initialize_records()noexcept;
    gameplay_world::PrimaryStartupReport start(gameplay_world::PrimaryStartupEffects*,
        const gameplay_world::PrimaryEquipmentContext* =nullptr)noexcept;
    gameplay_world::PrimaryStartupStatus close()noexcept;
    bool open()const noexcept{return !closed_&&session_.open();}
    bool bound_to(const NativeSession& value)const noexcept{return &value==&session_;}
    const gameplay_world::ActorAssets& actor_assets()const noexcept{return actors_;}
    const gameplay_world::HumanoidMotionAssets& motion_assets()const noexcept{return motion_assets_;}
    gameplay_world::HumanoidMotionOwner& motion_owner()noexcept{return motion_owner_;}
    gameplay_world::PrimaryActorModels& actor_models()noexcept{return models_;}
    const std::optional<gameplay_world::PrimaryStartupReport>& last_result()const noexcept{return last_;}
private:
    NativeSession& session_;
    gameplay_world::ActorAssets actors_;
    gameplay_world::HumanoidMotionAssets motion_assets_;
    gameplay_world::HumanoidMotionOwner motion_owner_;
    gameplay_world::PrimaryActorModels models_;
    std::optional<gameplay_world::PrimaryStartupReport> last_;
    bool running_{},closed_{};
};
}
