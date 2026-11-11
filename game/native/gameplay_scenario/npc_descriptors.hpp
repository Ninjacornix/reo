#pragma once
#include "../transform_math/transform_math.hpp"
#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <span>

namespace reo::native::gameplay_world { struct Session; }
namespace reo::native::gameplay_scenario {
class SceneResources;
class ResourceTemplates;

struct MissingCharacters {
    std::array<std::uint8_t,8> values{};
    std::optional<std::uint16_t> resolve(std::uint32_t id) const noexcept {
        if (id<200) return std::uint16_t(id);
        if (id-200>=values.size()) return {};
        return std::uint16_t(200+values[id-200]);
    }
};

// Persistent scenario descriptors have a lifetime independent of live actors.
// Parameter names retain their literal role where the content meaning is open.
struct NpcDescriptor {
    std::uint8_t active{},room{},category{},variant{},control_mode{},flags{};
    std::uint16_t template_id{},yaw{},health{},mode2_half{},behavior_flags{};
    transform_math::Vector position;
    std::uint8_t transition_state{},parameter{},mode_parameter{},selected_resource{};
    std::int8_t random_policy{};
    std::int32_t transition_timer{},behavior_state{};
    std::array<std::uint32_t,3> control_parameters{};
    std::array<std::uint8_t,4> inventory{};
    std::array<std::uint16_t,2> mode0_values{};
    std::uint32_t mode2_value{},mode2_parameter{};
};

class NpcDescriptors final {
public:
    static constexpr std::size_t capacity=64;
    void reset() noexcept { records_={}; }
    std::span<const NpcDescriptor,capacity> records() const noexcept { return records_; }
    NpcDescriptor* record(std::size_t index) noexcept {
        return index<capacity ? &records_[index] : nullptr;
    }
    // Complete1D45F0 decoding after successful file acquisition. Bounded input
    // is staged so malformed content preserves the previous descriptors.
    std::optional<std::size_t> import(std::span<const std::byte>) noexcept;
    bool enable(gameplay_world::Session&,std::int32_t template_id,
                std::array<std::uint32_t,3> parameters) noexcept; //684010
    void position(std::int32_t template_id,std::uint8_t room,
                  transform_math::Vector,std::uint16_t yaw) noexcept; //6841E0
    void health_flags(std::int32_t template_id,std::int32_t health,std::uint32_t mask) noexcept; //6842B0
    std::optional<std::size_t> disable(std::int32_t template_id) noexcept; //684450
    bool grant(SceneResources&,const ResourceTemplates&,std::int16_t template_id,
               std::int16_t content,std::int16_t quantity) noexcept; //68DBA0
    bool select(SceneResources&,std::int8_t template_id,std::int16_t content) noexcept; //68DF10
private:
    std::array<NpcDescriptor,capacity> records_{};
};
}
