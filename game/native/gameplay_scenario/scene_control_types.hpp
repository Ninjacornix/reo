#pragma once
#include <array>
#include <cstdint>
#include <optional>
#include <variant>
#include "model_reference.hpp"

namespace reo::native::gameplay_scenario {
// Type numbers are observed content tags, not guessed subsystem names. Typed
// values project only fields owned by these commands; no original byte layout.
struct ControlRouteDestination {std::uint32_t room{},edge{};friend bool operator==(const ControlRouteDestination&,const ControlRouteDestination&)=default;};
struct ControlModelReference {ModelReference model{};std::uint32_t descriptor{};friend bool operator==(const ControlModelReference&,const ControlModelReference&)=default;};
struct ControlMatrixProgramResource {ModelReference model_slot{};std::uint32_t descriptor{};std::uint32_t resource_class{};};
struct ControlTypeZero {std::uint32_t parameter{};std::uint16_t half_parameter{};std::uint8_t byte_parameter{},refresh_parameter{};std::optional<ControlRouteDestination> destination{};std::optional<ControlMatrixProgramResource> matrix_program{};};
struct ControlTypeOne {std::uint16_t parameter{};};
struct ControlTypeTwo {std::uint32_t selector{},parameter{};std::uint16_t half_parameter{};std::uint8_t byte_parameter{},refresh_parameter{};std::optional<ControlModelReference> model_reference{};std::optional<std::uint32_t> matrix_resource_class{};};
struct ControlTypeThree {std::uint32_t mode{};std::uint16_t parameter{};};
struct ControlTypeFour {std::uint32_t mode{},selector{};};
struct ControlTypeFive {std::uint16_t selector{},duration{},countdown{},secondary_parameter{};std::uint32_t completion{};std::uint8_t byte_parameter{};
    // Additional fields written by the complete reset. Their consumer roles
    // remain unresolved; they are typed state, not raw guest-layout storage.
    std::uint16_t reset_sentinel{};std::uint8_t reset_byte_a{},reset_byte_b{};
    std::array<float,3> position{};
    std::uint16_t effect_parameter{};};
struct ControlTypeNine {std::uint32_t parameter{};};
struct ControlTypeSix {std::uint32_t selector{};};
struct ControlTypeSeven {std::uint32_t selector{};};
struct ControlTypeEleven {};
struct ControlTypeThirteen {std::uint32_t selector{};std::uint16_t parameter{};};
struct ControlOther {std::uint8_t type{};};
using SceneControlBody=std::variant<ControlTypeZero,ControlTypeOne,ControlTypeTwo,ControlTypeThree,ControlTypeFour,ControlTypeFive,ControlTypeNine,ControlTypeThirteen,ControlOther,ControlTypeSix,ControlTypeSeven,ControlTypeEleven>;
struct SceneControl {std::uint32_t authored_id{};std::uint8_t enabled{};SceneControlBody body;std::uint8_t counter{};};
}
