#pragma once
#include "../afs_source_range/afs_source_range.hpp"
#include <array>
#include <memory>
#include <span>
#include <vector>

namespace reo::native::afs_hierarchy {
inline constexpr std::uint32_t maximum_depth=8;
enum class Status { completed, invalid_path, archive_refused, cache_capacity,
    entry_capacity, source_failure, no_memory };
struct Config { std::uint32_t archives{64},entries{65536},members_per_archive{65535}; };
struct Hop {
    std::uint32_t index{};afs_source_range::Entry entry;
    std::uint64_t root_byte_offset{};
};
struct Resolved {
    Status status{Status::invalid_path};afs_source_range::Status archive_status{afs_source_range::Status::completed};
    std::shared_ptr<const resources::ByteView> view;
    std::array<Hop,maximum_depth> hops{};std::uint32_t depth{},logical_bytes{};
};
struct Snapshot { std::uint32_t archives{},entries{};std::uint64_t root_bytes{}; };
// One externally serialized immutable root. Workers may retain resolved views
// independently; only resolution mutates the bounded index cache. No payload
// copy, synthetic tail bytes, path reopen, guest address or module global exists.
class Tree final {
public:
    Tree(std::shared_ptr<const resources::ByteView>,Config={});
    [[nodiscard]] Resolved resolve(std::span<const std::uint32_t> indices)noexcept;
    [[nodiscard]] Snapshot snapshot()const noexcept;
private:
    struct Cached {
        std::array<std::uint32_t,maximum_depth> path{};std::uint32_t depth{};
        std::shared_ptr<const afs_source_range::Archive> archive;
    };
    Config config_;std::shared_ptr<const resources::ByteView> root_;
    std::vector<Cached> cache_;std::uint32_t entries_{};
};
} // namespace reo::native::afs_hierarchy
