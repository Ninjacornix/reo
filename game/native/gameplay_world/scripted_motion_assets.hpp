#pragma once
#include "scripted_motion.hpp"
#include <span>

namespace reo::assets {struct Source;}
namespace reo::native::gameplay_world {
struct ScriptedMotionMember {
    std::uint16_t scenario{},clip{};
    std::uint8_t kind{}; // 0 body, 1 face, 2 head
    std::uint16_t member{};
};
std::span<const ScriptedMotionMember> file1_scripted_motion_members()noexcept;
enum class ScriptedMotionLoadStatus {loaded,not_found,source_failure,invalid_asset,no_memory};
struct ScriptedMotionLoad {
    ScriptedMotionBanks banks;
    std::array<ScriptedMotionLoadStatus,3> status{ScriptedMotionLoadStatus::not_found,
        ScriptedMotionLoadStatus::not_found,ScriptedMotionLoadStatus::not_found};
    std::array<std::optional<std::uint16_t>,3> members;
};
// Preparation outside the simulation owner: immutable retained archive reads
// and bank construction. Every file is attempted independently. Failed reads
// preserve the previous bank; successful loads preserve absent prior slots,
// matching1D1CC0/1D1960 without mutating a live bank or the source bytes.
class ScriptedMotionAssets final {
public:
    explicit ScriptedMotionAssets(std::shared_ptr<const reo::assets::Source>);
    ScriptedMotionLoad read(std::uint16_t scenario,std::uint16_t clip,
                            const ScriptedMotionBanks& previous={})const;
private:
    struct Member {std::uint64_t offset{};std::uint32_t bytes{};};
    std::shared_ptr<const reo::assets::Source> source_;
    std::vector<Member> members_;
};
}
