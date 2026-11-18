#pragma once
#include "common_actor_frame.hpp"
#include "auxiliary_actors.hpp"
namespace reo::native::gameplay_world {
// Camera position and update inhibition are borrowed from their native scene
// owner. There are no default camera coordinates or assumed enabled updates.
bool npc_camera_suppressed(const World&,Position actor,Position camera);
class NpcAttachmentFrames {
public:
    virtual ~NpcAttachmentFrames()=default;
    // Allocation claims and the renderer attachment active byte are distinct.
    virtual bool active(World&,std::uint8_t slot)=0;
    //373F40 model attachment work belongs to the renderer boundary. An absent
    // attachment does not request it; an occupied slot requires completion.
    virtual bool update(World&,actors::EntityId,std::uint8_t slot,std::uint16_t model)=0;
};
enum class NpcUpdateStatus {completed,busy,closed,unavailable};
struct NpcUpdated {NpcUpdateStatus status{NpcUpdateStatus::completed};std::size_t visited{},called{},suppressed{},attachments{};};
class NpcActorUpdates final {
public:
    NpcActorUpdates(World&,Services&,MotionTransformServices&,const Position& camera,
                    const std::uint8_t& inhibition,NpcAttachmentFrames* = nullptr);
    ~NpcActorUpdates();
    NpcActorUpdates(const NpcActorUpdates&)=delete;
    NpcActorUpdates& operator=(const NpcActorUpdates&)=delete;
    NpcUpdated run();
    NpcUpdateStatus close()noexcept;
private:
    World& world_;CommonActorFrame frame_;
    const Position& camera_;const std::uint8_t& inhibition_;
    NpcAttachmentFrames* attachments_;
    bool closed_{},running_{};
};
}
