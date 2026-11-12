#pragma once
#include "cutscene_actor_tracks.hpp"
#include "../gameplay_world/cinematic_object_attachment.hpp"
namespace reo::native::gameplay_scenario {
struct CutsceneObjectBinding {
    gameplay_scene::RecordId object;
    // Immutable construction metadata for the source category10B4/B8/BC view.
    // Missing is explicit unadmitted data, never a guessed unit scale.
    std::optional<animation::Vector> attachment_scale;
};
struct CutsceneObjectTrackGroup:CutsceneObjectBinding {
    std::array<std::shared_ptr<const CutsceneActorStream>,7> streams;
};
//5EF120's separate object streams. Media-event frame and pose scene frame
// remain distinct caller-owned clocks; this consumer advances neither clock.
class CutsceneObjectTracks final {
public:
    static constexpr std::size_t capacity=16;
    explicit CutsceneObjectTracks(gameplay_world::World&);
    ~CutsceneObjectTracks();
    CutsceneObjectTracks(const CutsceneObjectTracks&)=delete;
    CutsceneObjectTracks& operator=(const CutsceneObjectTracks&)=delete;
    CutsceneTrackStatus install(std::span<const CutsceneObjectTrackGroup>,
                               std::span<const gameplay_actors::EntityId> actors={});
    CutsceneTracksUpdated tick(const std::uint32_t& media_frame);
    CutsceneTrackStatus close()noexcept;
    std::optional<std::size_t> cursor(std::size_t group,std::size_t stream)const noexcept;
    bool failed()const noexcept{return failed_;}
private:
    struct Group {CutsceneObjectTrackGroup binding;std::array<std::optional<std::size_t>,7> positions;};
    gameplay_world::World& world_;
    std::vector<Group> groups_;
    std::vector<gameplay_actors::EntityId> actors_;
    bool running_{},closed_{},failed_{};
};
}
