#pragma once
#include "../gameplay_collision/room_damage.hpp"
#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <span>
#include <vector>

namespace reo::native::gameplay_scenario::content {
using Bytes=std::shared_ptr<const std::vector<std::byte>>;
struct Range {std::uint32_t offset{},bytes{};friend bool operator==(const Range&,const Range&)=default;};
// Original callbacks use size!=0 to select a section. Offset0 is not a separate
// absence marker; native admission checks its entire declared extent.
class RdtDirectory final {
public:
    explicit RdtDirectory(Bytes);
    std::optional<Range> range(std::size_t index)const noexcept;
    std::optional<std::span<const std::byte>> section(std::size_t index)const noexcept;
    Bytes backing()const noexcept{return bytes_;}
private:
    Bytes bytes_;
    std::array<Range,32> sections_;
};
enum class BankFormat { scenario_evb,room_section };
enum class ObjectRole { executable_candidate,configuration_data,indirect_references,unknown };
struct ObjectBound {std::uint8_t table_index{};ObjectRole role{};Range bound;};
// Relative table offsets from the original content loader, never relocated guest
// pointers. A next-object boundary is only an upper bound: code can have embedded
// or trailing noncode. This importer never scans an entire bound as bytecode.
class ScriptBank final {
public:
    ScriptBank(Bytes,BankFormat);
    BankFormat format()const noexcept{return format_;}
    std::size_t table_size()const noexcept{return count_;}
    std::optional<ObjectBound> object(std::size_t index)const noexcept;
    std::vector<ObjectBound> executable_candidates()const;
    std::optional<std::vector<std::uint32_t>> indirect_references(std::size_t index)const;
    Bytes backing()const noexcept{return bytes_;}
    std::span<const std::byte> view(const ObjectBound&)const;
private:
    Bytes bytes_;
    BankFormat format_;
    std::size_t count_{};
    std::array<std::uint32_t,32> offsets_{};
};
// The relocated EVB top-level word at +0x34 is object 13.
std::optional<gameplay_collision::delivery::RoomCounterPolicy::ScenarioRows>
import_room_counter_rows(const ScriptBank&);
} // namespace reo::native::gameplay_scenario::content
