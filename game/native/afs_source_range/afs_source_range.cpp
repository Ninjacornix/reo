#include "afs_source_range.hpp"
#include <algorithm>
#include <array>
#include <climits>
#include <new>
#include <span>

namespace reo::native::afs_source_range {
namespace {
std::uint32_t word(std::span<const std::byte> data, std::size_t at) noexcept {
    std::uint32_t value = 0;
    for (unsigned i = 0; i < 4; ++i) value |= std::uint32_t(data[at + i]) << (i * 8);
    return value;
}
bool exact(const resources::ByteView& view, std::uint64_t at, std::span<std::byte> output) {
    const auto result = view.read(at, output);
    return result.status == resources::Status::ok && result.bytes == output.size();
}
}
OpenRange prepare_open(std::uint32_t start, std::uint32_t count, std::uint32_t backend) noexcept {
    constexpr auto maximum = std::uint32_t(INT32_MAX) / 2048;
    if (start > maximum || count > maximum || backend > maximum) return {};
    if (count == 0xfffffu) return {Status::completed, start, backend * 2048u, start == 0};
    start = std::min(start, backend);
    count = std::min(count, backend - start);
    return {Status::completed, start, count * 2048u, true};
}
OpenResult Archive::open(std::shared_ptr<const resources::ByteView> parent,
    std::uint64_t offset, std::uint64_t bytes, std::uint32_t maximum) noexcept {
    if (!parent) return {Status::invalid_source, {}};
    if (offset > parent->size() || bytes > parent->size() - offset || bytes < 8) return {Status::invalid_range, {}};
    if (!maximum || maximum > 65536) return {Status::unsupported_profile, {}};
    try {
        std::array<std::byte, 8> prefix{};
        if (!exact(*parent, offset, prefix)) return {Status::source_failure, {}};
        if (word(prefix, 0) != 0x00534641u) return {Status::bad_magic, {}};
        const auto count = word(prefix, 4);
        // Original descriptor construction retains a 16-bit member count.
        // Exclude the 65536 boundary rather than inventing a wider table ABI.
        if (!count || count >= 65536 || count > maximum) return {Status::unsupported_profile, {}};
        const auto table_bytes = std::uint64_t(count) * 8;
        if (table_bytes > bytes - 8) return {Status::malformed_index, {}};
        std::vector<std::byte> table(static_cast<std::size_t>(table_bytes));
        if (!exact(*parent, offset + 8, table)) return {Status::source_failure, {}};
        auto archive = std::shared_ptr<Archive>(new Archive);
        archive->parent_ = std::move(parent); archive->offset_ = offset; archive->entries_.reserve(count);
        const auto first = word(table, 0);
        if (first % 2048 || first < 8 + table_bytes) return {Status::unsupported_profile, {}};
        std::uint64_t cursor = first;
        for (std::uint32_t i = 0; i < count; ++i) {
            const auto raw_offset = word(table, std::size_t(i) * 8), length = word(table, std::size_t(i) * 8 + 4);
            const auto sectors = (std::uint64_t(length) + 2047) / 2048;
            if (length && raw_offset != cursor) return {Status::unsupported_profile, {}};
            if (cursor > bytes || sectors * 2048 > bytes - cursor) return {Status::invalid_range, {}};
            if (cursor > INT32_MAX || sectors * 2048 > INT32_MAX || cursor + sectors * 2048 > INT32_MAX)
                return {Status::unsupported_profile, {}};
            archive->entries_.push_back({static_cast<std::uint32_t>(cursor / 2048),static_cast<std::uint32_t>(sectors),length});
            cursor += sectors * 2048;
        }
        return {Status::completed, std::move(archive)};
    } catch (const std::bad_alloc&) { return {Status::no_memory, {}}; }
      catch (...) { return {Status::source_failure, {}}; }
}
const Entry* Archive::entry(std::uint32_t index) const noexcept {
    return index < entries_.size() ? &entries_[index] : nullptr;
}
Member Archive::member(std::uint32_t index) const noexcept {
    const auto* selected = entry(index);
    if (!selected) return {};
    auto view = resources::bounded_view(parent_, offset_ + std::uint64_t(selected->start_sector) * 2048,
                                        std::uint64_t(selected->sectors) * 2048);
    if (view.status != resources::Status::ok)
        return {view.status == resources::Status::no_memory ? Status::no_memory : Status::source_failure, *selected, {}};
    return {Status::completed, *selected, std::move(view.view)};
}
} // namespace reo::native::afs_source_range
