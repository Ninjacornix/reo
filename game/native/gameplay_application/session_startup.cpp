#include "session_startup.hpp"
#include <stdexcept>
#include <utility>
namespace reo::native::gameplay_application {
namespace {
NativeSession& admitted(NativeSession& session,const std::shared_ptr<const gameplay_world::HumanoidMotionBanks>& banks){
    if(!session.open()||session.update().busy()||session.world().busy()||!banks)
        throw std::invalid_argument("Canonical session startup capabilities unavailable");
    return session;
}
}
SessionStartup::SessionStartup(NativeSession& session,std::shared_ptr<const reo::assets::Source> source,
    std::shared_ptr<const gameplay_world::HumanoidMotionBanks> banks):
    session_(admitted(session,banks)),actors_(source),motion_assets_(std::move(source)),
    motion_owner_(session.world()),models_(session.world(),motion_owner_){
    const auto result=motion_owner_.publish(std::move(banks));
    if(result.status!=gameplay_world::HumanoidPublicationStatus::completed)
        throw std::invalid_argument("Canonical session motion publication unavailable");
}
SessionStartup::~SessionStartup(){if(running_||close()==gameplay_world::PrimaryStartupStatus::busy)std::terminate();}
gameplay_world::PrimaryRecordsInitialized SessionStartup::initialize_records()noexcept{
    if(!open())return{gameplay_world::PrimaryRecordsStatus::closed};
    if(running_||session_.world().busy()||session_.update().busy())return{gameplay_world::PrimaryRecordsStatus::busy};
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    return gameplay_world::initialize_primary_records(session_.world());
}
gameplay_world::PrimaryStartupReport SessionStartup::start(gameplay_world::PrimaryStartupEffects* effects,
    const gameplay_world::PrimaryEquipmentContext* equipment)noexcept{
    if(!open())return{gameplay_world::PrimaryStartupStatus::closed};
    if(running_||session_.world().busy()||session_.update().busy())return{gameplay_world::PrimaryStartupStatus::busy};
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    const gameplay_world::PrimaryStartupContext context{
        session_.update(),actors_,motion_assets_,&session_.archive(),effects,equipment};
    last_=models_.start_roster(context);return *last_;
}
gameplay_world::PrimaryStartupStatus SessionStartup::close()noexcept{
    if(closed_)return gameplay_world::PrimaryStartupStatus::completed;
    if(running_||session_.world().busy()||session_.update().busy())return gameplay_world::PrimaryStartupStatus::busy;
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    if(models_.close()!=gameplay_world::PrimaryModelStatus::completed||
       motion_owner_.close()!=gameplay_world::HumanoidPublicationStatus::completed)
        return gameplay_world::PrimaryStartupStatus::busy;
    closed_=true;last_.reset();return gameplay_world::PrimaryStartupStatus::completed;
}
}
