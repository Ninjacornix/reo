#pragma once
#include "cutscene_actor_commands.hpp"
namespace reo::native::gameplay_scenario {
// Immutable authored records. Imports copy their bytes; caller storage and
// original relocated pointers are never retained. Empty means no stream.
class CutsceneActorStream final {
public:
    static std::shared_ptr<const CutsceneActorStream> import(std::span<const std::byte>);
    std::size_t size()const noexcept{return records_.size();}
    std::span<const std::byte,36> record(std::size_t)const;
    std::uint16_t frame(std::size_t)const;
private:
    std::vector<std::array<std::byte,36>> records_;
};
struct CutsceneActorTrackGroup {
    std::int8_t kind{};
    gameplay_actors::EntityId actor;
    std::array<std::shared_ptr<const CutsceneActorStream>,7> streams;
};
enum class CutsceneTrackStatus {completed,busy,closed,invalid_input,no_memory,unavailable,failed};
struct CutsceneTracksUpdated {
    CutsceneTrackStatus status{CutsceneTrackStatus::completed};
    std::size_t visited{},matched{},commands{},skipped{},ended{};
};
class CutsceneActorTracks final {
public:
    static constexpr std::size_t capacity=32,maximum_records=65536;
    explicit CutsceneActorTracks(gameplay_world::World&);
    ~CutsceneActorTracks();
    CutsceneActorTracks(const CutsceneActorTracks&)=delete;
    CutsceneActorTracks& operator=(const CutsceneActorTracks&)=delete;
    CutsceneTrackStatus install(std::span<const CutsceneActorTrackGroup>);
    // Reload frame, mode and scene for each stream after earlier commands.
    // Frame increment and the cinematic phase lifecycle belong to the caller.
    CutsceneTracksUpdated tick(const std::uint32_t& frame,const std::uint8_t& scene,CutsceneSpeech* = nullptr);
    CutsceneTrackStatus close()noexcept;
    bool busy()const noexcept{return running_;}
    bool failed()const noexcept{return failed_;}
    std::size_t size()const noexcept{return groups_.size();}
    std::optional<std::size_t> cursor(std::size_t group,std::size_t stream)const noexcept;
private:
    struct Group {CutsceneActorTrackGroup binding;std::array<std::optional<std::size_t>,7> positions;};
    gameplay_world::World& world_;
    std::vector<Group> groups_;
    bool running_{},closed_{},failed_{};
};
}
