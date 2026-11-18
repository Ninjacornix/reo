#pragma once
#include "../animation/motion_bank.hpp"
#include <optional>
namespace reo::assets {struct Source;}
namespace reo::native::gameplay_world {
struct CinematicObjectMotionMember {std::uint16_t scenario{},area{},member{};};
std::span<const CinematicObjectMotionMember> file1_cinematic_object_motion_members()noexcept;
enum class CinematicObjectMotionStatus {loaded,not_found,source_failure,invalid_asset,no_memory};
struct CinematicObjectMotionLoad {
    std::shared_ptr<const animation::MotionBank> bank;
    CinematicObjectMotionStatus status{CinematicObjectMotionStatus::not_found};
    std::optional<std::uint16_t> member;
};
//1D1E00/1D1960 preparation outside simulation. The bank is keyed by scenario
// and request area only; scene/suffix never select a different object bank.
// Failed reads preserve the old bank. Successful reads copy it before applying
// literal200-stride writes, retaining absent source slots and existing leases.
class CinematicObjectMotionAssets final {
public:
    explicit CinematicObjectMotionAssets(std::shared_ptr<const reo::assets::Source>);
    CinematicObjectMotionLoad read(std::uint16_t scenario,std::uint16_t area,
        std::shared_ptr<const animation::MotionBank> previous={})const;
private:
    struct Member {std::uint64_t offset{};std::uint32_t bytes{};};
    std::shared_ptr<const reo::assets::Source> source_;
    std::vector<Member> members_;
};
}
