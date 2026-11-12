#pragma once
#include "facial_assets.hpp"
#include "../animation/facial_curves.hpp"
#include "../gameplay_world/world.hpp"
namespace reo::native::gameplay_scenario {
class CutscenePlayback;
struct CutscenePlaybackState;
enum class FacialStatus {completed,busy,closed,unavailable,no_memory};
struct FacialLoaded {FacialStatus status{FacialStatus::unavailable};bool matrix_loaded{},lip_loaded{};};
struct FacialClaimed {FacialStatus status{FacialStatus::unavailable};std::optional<std::size_t> slot;};
struct FacialUpdated {FacialStatus status{FacialStatus::completed};std::size_t visited{},sampled{},patched{};bool stopped{};};
struct FacialInstance {
    animation::FacialCursor cursor{false};
    std::uint8_t matrix{};
    gameplay_actors::EntityId actor;
    std::array<std::size_t,5> origins{};
};
// Sole cinematic face population, registered through the existing playback
// controller. The bounded workspace is actual asset storage: MAT sector tails
// overlap3072-byte banks, and67C250 preserves these bytes across bookkeeping
// resets. It contains no CPU state or general addressed-memory interface.
class FacialMotions final {
public:
    FacialMotions(gameplay_world::World&,CutscenePlaybackState&,std::shared_ptr<const File1FacialAssets>);
    ~FacialMotions();
    FacialMotions(const FacialMotions&)=delete;
    FacialMotions& operator=(const FacialMotions&)=delete;
    FacialStatus reset()noexcept; //67C250
    FacialLoaded load(gameplay_actors::EntityId,std::uint16_t cue,std::uint16_t voice,std::uint16_t facial)noexcept; //67C2E0
    FacialClaimed claim(gameplay_actors::EntityId,std::uint16_t facial,std::uint16_t cue,std::uint16_t voice)noexcept; //67C590
    FacialUpdated tick()noexcept; //67C2D0 ->67C6D0, actual5FF1B0 outer position
    bool bound_to(const gameplay_world::World&,const CutscenePlaybackState&)const noexcept;
    bool busy()const noexcept{return running_;}
    const auto& instances()const noexcept{return instances_;}
    std::span<const std::byte> workspace()const noexcept{return workspace_;}
    std::size_t matrix_count()const noexcept{return matrix_count_;}
    std::size_t lip_count()const noexcept{return lip_count_;}
    std::size_t lip_end()const noexcept{return lip_end_;}
private:
    friend class CutscenePlayback;
    struct MatrixKey {std::uint8_t facial{};gameplay_actors::EntityId actor;};
    struct LipRecord {std::size_t offset{};std::uint16_t cue{},voice{};};
    gameplay_world::World& world_;CutscenePlaybackState& state_;
    std::shared_ptr<const File1FacialAssets> assets_;
    CutscenePlayback* controller_{};
    std::array<std::byte,65536> workspace_{};
    std::array<MatrixKey,8> matrices_;
    std::array<LipRecord,32> lips_;
    std::array<FacialInstance,8> instances_;
    std::size_t matrix_count_{},lip_count_{},lip_end_{};
    bool initialized_{},running_{};
    FacialStatus admission(bool allow_world_busy=false)const noexcept;
    void copy_asset(std::size_t,const FacialAssetBytes&);
    std::shared_ptr<const animation::FacialCurves> curves(const FacialInstance&)const;
};
} // namespace reo::native::gameplay_scenario
