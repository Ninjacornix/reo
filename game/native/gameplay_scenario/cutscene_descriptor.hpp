#pragma once
#include "cutscene_actor_tracks.hpp"
namespace reo::native::gameplay_scenario::content {class ScenarioArchive;}
namespace reo::native::gameplay_scenario {
struct CutsceneSection {std::uint32_t offset{},count{};std::uint16_t stride{};};
struct CutsceneActorBinding {std::int8_t kind{};gameplay_actors::EntityId actor;};
enum class CutsceneTail {complete,explicit_terminal,caller_terminal};
// Immutable0950 asset ownership. Sections are bounded asset offsets, not
// relocated pointers into a simulated address space or mutable scene state.
class CutsceneDescriptor final {
public:
    static constexpr std::size_t maximum_bytes=32u*1024u*1024u,maximum_groups=32;
    static std::shared_ptr<const CutsceneDescriptor> import(std::span<const std::byte>);
    std::array<std::uint8_t,3> identity()const noexcept{return identity_;}
    std::uint32_t duration()const noexcept{return duration_;}
    const CutsceneSection& camera_selection()const noexcept{return camera_selection_;}
    const auto& camera_streams()const noexcept{return camera_streams_;}
    const CutsceneSection& events()const noexcept{return events_;}
    const CutsceneSection& general()const noexcept{return general_;}
    const auto& actor_groups()const noexcept{return actors_;}
    const auto& object_groups()const noexcept{return objects_;}
    const CutsceneSection& secondary()const noexcept{return secondary_;}
    const auto& extension_groups()const noexcept{return extension_;}
    const auto& tail_first()const noexcept{return tail_first_;}
    const auto& tail_second()const noexcept{return tail_second_;}
    const auto& tail_last()const noexcept{return tail_last_;}
    CutsceneTail tail_kind()const noexcept{return tail_;}
    std::size_t consumed_bytes()const noexcept{return consumed_;}
    std::span<const std::byte> section(CutsceneSection)const;
    std::span<const std::byte> trailing_data()const noexcept{return std::span(bytes_).subspan(consumed_);}
    std::uint32_t header_word(std::size_t)const;
    // Actor construction supplies real native bindings. This preparation
    // copies the seven command streams; the eighth remains a header view.
    std::vector<CutsceneActorTrackGroup> actor_tracks(std::span<const CutsceneActorBinding>)const;
private:
    std::vector<std::byte> bytes_;
    std::array<std::uint8_t,3> identity_;
    std::uint32_t duration_{};
    CutsceneSection camera_selection_,events_,general_,secondary_;
    std::vector<std::array<CutsceneSection,2>> camera_streams_;
    std::vector<std::array<CutsceneSection,8>> actors_;
    std::vector<std::array<CutsceneSection,7>> objects_;
    std::optional<std::vector<std::array<CutsceneSection,2>>> extension_;
    std::optional<CutsceneSection> tail_first_,tail_second_,tail_last_;
    CutsceneTail tail_{CutsceneTail::complete};
    std::size_t consumed_{};
};
// Actual retained scenario AFS reads, outside simulation invocation. Missing
// named content returns null; unadmitted versions/data throw visibly.
std::shared_ptr<const CutsceneDescriptor> read_cutscene_descriptor(const content::ScenarioArchive&,
    std::uint16_t scenario,std::uint8_t sequence,std::uint8_t variant,std::uint8_t suffix);
}
