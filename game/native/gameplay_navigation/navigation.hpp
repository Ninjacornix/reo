#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <span>
#include <vector>

namespace reo::native::gameplay_navigation {
struct Position {float x{},y{},z{};};
struct Node {
    std::uint8_t active{};
    std::int8_t neighbor_count{};
    std::uint16_t group{};
    Position position;
    std::int32_t condition{-1};
    std::array<std::int8_t,4> neighbors{};
    std::array<std::uint16_t,4> actions{};
    std::array<std::uint16_t,4> costs{};
    std::array<std::uint32_t,4> packed_conditions{};
};
// These are authored encodings, not mutable emulated runtime records.
using Condition = std::array<std::uint8_t,16>;
using RouteCandidates = std::array<std::uint8_t,4>;
struct CrossRoomLink {
    std::int8_t room{},variant{},node{},condition{};
    std::array<std::uint8_t,8> operands{}; // Not yet assigned semantic names.
};
enum class ImportError {none,size,version,layout,budget,coordinates};
struct ImportFailure {ImportError reason{ImportError::none};std::size_t offset{};};
class RoomGraph {
public:
    std::span<const Node> nodes()const noexcept{return nodes_;}
    std::span<const Condition> conditions()const noexcept{return conditions_;}
    std::span<const RouteCandidates> routes()const noexcept{return routes_;}
    const std::array<std::uint8_t,4>& initial_edge_flags()const noexcept{return initial_edge_flags_;}
    // Relative offset retained as file identity; bytes are never relocated.
    std::uint32_t source_offset()const noexcept{return source_offset_;}
    std::span<const std::uint8_t> encoding()const noexcept{return encoding_;}
    // Bounded by the next greater authored entry or resource end. This is a
    // safe encoding view, not a claim that the encoded entry uses every byte.
    std::span<const std::uint8_t> condition_directory_entry(std::size_t)const noexcept;
    //8163B0/700330 expose this actual embedded16-entry room-section table.
    // Its relative offsets stay immutable; native ScriptBank owns relocation.
    std::span<const std::uint8_t> script_encoding()const noexcept{return std::span(encoding_).subspan(directory_base_);}
private:
    friend class Asset;
    friend class Bank;
    std::uint32_t source_offset_{};
    std::vector<Node> nodes_;
    std::vector<Condition> conditions_;
    std::size_t condition_base_{};
    std::size_t directory_base_{};
    std::vector<RouteCandidates> routes_;
    std::array<std::size_t,16> directory_entries_{};
    std::array<std::uint8_t,4> initial_edge_flags_{};
    std::vector<std::uint8_t> encoding_;
};
struct RoomDescriptor {
    std::int16_t room{},variant{};
    std::uint32_t extra{}; // Authored field; not asserted to be a size.
    std::size_t graph{};
};
class Asset {
public:
    // Bounded File #1 SGL profile. No process memory, file I/O or state binding.
    static std::optional<Asset> read(std::span<const std::uint8_t>,ImportFailure&);
    std::span<const RoomDescriptor> descriptors()const noexcept{return descriptors_;}
    std::span<const RoomGraph> graphs()const noexcept{return graphs_;}
    std::span<const CrossRoomLink> links()const noexcept{return links_;}
    std::span<const std::uint8_t> adjacency()const noexcept{return adjacency_;}
    std::span<const std::uint8_t> initial_visit_masks()const noexcept{return initial_visit_masks_;}
    // Original binding walks descriptors in order: last matching key wins.
    const RoomGraph* find_room(std::int32_t room,std::int32_t variant)const noexcept;
private:
    std::vector<RoomDescriptor> descriptors_;
    std::vector<RoomGraph> graphs_;
    std::vector<CrossRoomLink> links_;
    std::vector<std::uint8_t> adjacency_,initial_visit_masks_;
};
enum class QueryStatus {completed,unavailable};
struct NodeResult {QueryStatus status{QueryStatus::unavailable};std::int8_t node{-1};};
struct ActionResult {QueryStatus status{QueryStatus::unavailable};std::int32_t action{-1};};
// Complete8171E0 unfiltered finite-distance profile (including8171D0 group0).
// Empty candidates are unavailable: the original reads an uninitialized slot.
NodeResult nearest_node(const RoomGraph&,Position,std::int8_t group)noexcept;
// Complete8196E0 bounded valid-neighbor/condition profile. Completed -1 is a
// measured no-action result; unavailable never reads adjacent asset sections.
ActionResult reverse_edge_action(const RoomGraph&,std::int32_t node)noexcept;
}
