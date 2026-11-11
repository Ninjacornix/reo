#pragma once
#include "cutscene_actor.hpp"
#include "linked_models.hpp"
namespace reo::native::gameplay_world {
struct LinkedExpiryNotice {
    std::uint8_t mode{},ordinal{};
    static constexpr unsigned channel=8,type=0x49,length=6,options=0,dispatch_mode=4;
};
class LinkedExpirySink {
public:
    virtual ~LinkedExpirySink()=default;
    virtual bool expired(const LinkedExpiryNotice&)noexcept=0;
};
enum class LinkedUpdateStatus {completed,busy,closed,unavailable};
struct LinkedUpdated {
    LinkedUpdateStatus status{LinkedUpdateStatus::completed};
    std::size_t visited{},called{},poses{},center_initializations{},expired{},publication_failures{};
    bool periodic{};
};
class LinkedActorUpdates final {
public:
    LinkedActorUpdates(World&,ScriptedMotionBanks,std::shared_ptr<const gameplay_collision::response::Grid>,LinkedExpirySink* = nullptr);
    ~LinkedActorUpdates();
    LinkedActorUpdates(const LinkedActorUpdates&)=delete;
    LinkedActorUpdates& operator=(const LinkedActorUpdates&)=delete;
    LinkedUpdated run();
    LinkedUpdateStatus close()noexcept;
private:
    World& world_;
    std::shared_ptr<const gameplay_collision::response::Grid> floors_;
    ScriptedActorMotion motion_;
    CutsceneActor cutscene_;
    GridSurfaceOrientation pose_;
    LinkedExpirySink* publication_;
    bool closed_{},running_{};
};
}
