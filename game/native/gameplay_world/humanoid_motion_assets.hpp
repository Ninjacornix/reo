#pragma once
#include "npc_actor_construction.hpp"
#include "scripted_motion_assets.hpp"
namespace reo::native::gameplay_world {
struct HumanoidMotionRevision;
struct HumanoidMotionMember {std::uint16_t index{};std::uint8_t character{255};std::uint16_t member{};std::string_view name;};
std::span<const HumanoidMotionMember> file1_humanoid_motion_members()noexcept;
// One immutable publication keeps shared source bank identities coherent.
// The general bank and scene other_modes bank are the SAME destination.
class HumanoidMotionBanks final {
public:
    const ScriptedMotionBanks& scripted()const noexcept{return scripted_;}
    bool base_loaded()const noexcept{return base_loaded_;}
    bool follows(const HumanoidMotionBanks& current)const noexcept{return revision_&&(revision_==current.revision_||parent_==current.revision_);}
    std::shared_ptr<const animation::MotionBank> bank(HumanoidMotionAlias)const noexcept;
    const std::shared_ptr<const animation::MotionBank>& alternate_style()const noexcept{return alternate_style_;}
    const std::shared_ptr<const animation::MotionBank>& character(std::size_t index)const{return characters_.at(index);}
    NpcMotionBindings npc_bindings()const;
private:
    friend class HumanoidMotionAssets;
    HumanoidMotionBanks()=default;
    ScriptedMotionBanks scripted_;
    std::shared_ptr<const animation::MotionBank> alternate_style_;
    std::array<std::shared_ptr<const animation::MotionBank>,8> characters_;
    std::shared_ptr<const animation::MotionBank> primary_;
    bool base_loaded_{};
    std::shared_ptr<const HumanoidMotionRevision> revision_,parent_;
};
struct HumanoidSceneMotionLoad {
    std::shared_ptr<const HumanoidMotionBanks> banks;
    std::array<ScriptedMotionLoadStatus,3> status{ScriptedMotionLoadStatus::not_found,
        ScriptedMotionLoadStatus::not_found,ScriptedMotionLoadStatus::not_found};
    std::array<std::optional<std::uint16_t>,3> members;
};
// Content preparation outside simulation callbacks. Throws on missing common
// or character input; failed preparation cannot mutate a published snapshot.
class HumanoidMotionAssets final {
public:
    explicit HumanoidMotionAssets(std::shared_ptr<const reo::assets::Source>);
    // Initial1D1A80/1D19D0 profile, with independently absent character/demo banks.
    std::shared_ptr<const HumanoidMotionBanks> base()const;
    // Complete default-load gate: a scene load invalidates it, including a
    // failed scene read. Rebuilding preserves unrelated banks and old leases.
    std::shared_ptr<const HumanoidMotionBanks> ensure_base(std::shared_ptr<const HumanoidMotionBanks> previous)const;
    //1D1B10: common overlay mode1, followed by selected PLxx_PC_000 banks mode1.
    std::shared_ptr<const HumanoidMotionBanks> overlay(std::uint16_t common_index,
        std::span<const std::uint8_t> characters,const HumanoidMotionBanks& previous)const;
    // Existing scene loader preserves each previous bank on missing/failed
    // input, including the shared general/head-motion destination.
    HumanoidSceneMotionLoad scene(std::uint16_t scenario,std::uint16_t clip,const HumanoidMotionBanks& previous)const;
    //5EC0E0/1B1BC0: release one shared character bank, preserving its type byte.
    // Previously retained clips remain alive through their native leases.
    std::shared_ptr<const HumanoidMotionBanks> release_character(std::uint8_t character,const HumanoidMotionBanks& previous)const;
    // Complete1B1DF0: release family0 in common/alternate and all prepared
    // character banks, then invalidate the common-default-loaded gate.
    std::shared_ptr<const HumanoidMotionBanks> release_base(const HumanoidMotionBanks& previous)const;
private:
    struct Member {std::uint64_t offset{};std::uint32_t bytes{};std::string name;};
    std::shared_ptr<const reo::assets::Source> source_;
    ScriptedMotionAssets scripted_;
    std::vector<Member> members_;
    std::pair<std::vector<std::byte>,std::string> read(std::uint16_t index,std::uint8_t character)const;
    void load_defaults(HumanoidMotionBanks&)const;
    static void clear_base_family(HumanoidMotionBanks&);
};
}
