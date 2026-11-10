#pragma once
#include "game/native/gameplay_actors/entity.hpp"
#include <array>
#include <cstdint>
#include <memory>
#include <optional>
#include "../transform_math/transform_math.hpp"
namespace reo::native::gameplay_world {struct InventorySlots;}

namespace reo::native::gameplay_scenario {
struct SceneResourceDomain;
class SceneResources;
class ResourceTemplates;
class SceneResourceId final {
public:
    SceneResourceId()=default;
    explicit operator bool()const noexcept{return bool(domain_);}
    friend bool operator==(const SceneResourceId&,const SceneResourceId&)=default;
private:
    std::shared_ptr<const SceneResourceDomain> domain_;
    std::uint64_t generation_{};
    std::uint16_t slot_{};
    friend class SceneResources;
};
// A native live-object capability, not an encoded original pointer. The actual
// scene-object owner implements this interface; this module does not own actors.
class SceneAttachment {
public:
    virtual ~SceneAttachment()=default;
};
class SceneFlagAttachment:public SceneAttachment {
public:
    virtual void flag(std::uint32_t mask,bool set)noexcept=0;
};
struct SceneDescriptor {
    std::uint8_t active{},room{},instance_index{},kind{};
    std::uint16_t authored_id{},attachment_id{},ownership_tag{};
    std::int16_t parameter{};
    std::uint32_t flags{};
    std::shared_ptr<SceneAttachment> primary,secondary;
    std::uint8_t template_index{255}; // original descriptor byte2B, independent of kind
    transform_math::Vector position;
    std::uint16_t tilt{},yaw{};
    std::int8_t shape_profile{},orientation_variant{};
    std::uint8_t claim_tag{}; // original2A; independent of the owner halfword
    std::uint16_t saved_yaw{};
    transform_math::Vector saved_position; // placement preserved while kind is nonzero
};
enum class SceneEffect { construct_primary,construct_alternate,release,retire_instance };
enum class SceneStatus;
class SceneEffects {
public:
    virtual ~SceneEffects()=default;
    // Construct effects receive the stable descriptor identity. Release also
    // preserves the original byte-sized instance index, including zero.
    virtual SceneStatus apply(SceneResources&,const SceneResourceId&,SceneEffect,std::uint8_t instance_index)noexcept=0;
};
enum class SceneCommand { enable,disable,force_enable,alternate_enable };
enum class SceneStatus { completed,invalid_identity,provider_unavailable,invalid_slot,generation_exhausted,full };
struct SceneAllocated {SceneStatus status{SceneStatus::full};std::optional<SceneResourceId> id;std::uint8_t slot{};};
enum class SceneOwnerFamily { primary,extended };
struct SceneOwnerReference {SceneOwnerFamily family{};std::uint16_t index{};friend bool operator==(const SceneOwnerReference&,const SceneOwnerReference&)=default;};
struct AttachedSceneResource {SceneResourceId id;SceneOwnerReference owner;};
class SceneOwners {
public:
    virtual ~SceneOwners()=default;
    virtual std::optional<gameplay_actors::EntityId> resolve(SceneOwnerReference)noexcept=0;
    virtual SceneStatus detach(SceneResources&,const gameplay_actors::EntityId&,std::uint8_t instance_index)noexcept=0;
    virtual SceneStatus refresh(SceneResources&,const gameplay_actors::EntityId&)noexcept=0;
};
// Externally serialized native descriptor owner. Loading a slot retires its old
// identity; authored lookup preserves the original first-of-256 ordering.
class SceneResources final {
public:
    static constexpr std::size_t capacity=256;
    SceneResources();
    SceneResources(const SceneResources&)=delete;
    SceneResources& operator=(const SceneResources&)=delete;
    std::optional<SceneResourceId> load(std::size_t,SceneDescriptor);
    // Complete591AE0 scans1..255, preserving slot0 and the255-active gate.
    SceneAllocated allocate(std::uint8_t room,std::uint16_t authored_id,
        std::uint16_t attachment_id,const ResourceTemplates&);
    // Exact resource-table slot, including inactive descriptors. No authored-ID search.
    std::optional<SceneResourceId> slot(std::size_t)const noexcept;
    std::optional<SceneResourceId> lookup(std::int16_t authored_id)const noexcept;
    std::optional<AttachedSceneResource> lookup_attached(std::int16_t attachment_id)const noexcept;
    std::optional<SceneDescriptor> get(const SceneResourceId&)const noexcept;
    // Complete5F2210 read of the canonical inventory and descriptor+6 content.
    std::uint8_t find_inventory_content(const gameplay_world::InventorySlots&,std::uint32_t)const noexcept;
    SceneStatus replace(const SceneResourceId&,SceneDescriptor)noexcept;
    // Complete591BE0. Count is a derived view of this same canonical table.
    SceneStatus deactivate(const SceneResourceId&)noexcept;
    std::uint16_t active_count()const noexcept;
    SceneStatus command(const SceneResourceId&,SceneCommand,std::uint16_t current_room,SceneEffects*)noexcept;
    std::optional<bool> inactive_or_flag29(const SceneResourceId&)const noexcept;
    SceneStatus flag800(const SceneResourceId&,std::int8_t value)noexcept;
    SceneStatus detach(const AttachedSceneResource&,SceneEffects*,SceneOwners*)noexcept;
    // Missing/ineligible attachment fails. Invalid signed operator values
    // bypass the comparison only after a valid attachment was found.
    bool compare_attached(std::int16_t attachment_id,std::int16_t expected,std::int16_t operation)const noexcept;
private:
    std::shared_ptr<const SceneResourceDomain> domain_;
    std::array<SceneDescriptor,capacity> descriptors_;
    std::array<std::uint64_t,capacity> generations_;
    bool valid(const SceneResourceId&)const noexcept;
    SceneResourceId identity(std::size_t)const noexcept;
};
} // namespace reo::native::gameplay_scenario
