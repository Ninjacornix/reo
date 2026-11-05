#include "bounded_view.hpp"

#include <new>
#include <utility>

namespace reo::native::resources {
namespace {
class BoundedView final : public ByteView {
public:
    BoundedView(std::shared_ptr<const ByteView> parent, std::uint64_t base,
                std::uint64_t bytes) noexcept : parent_(std::move(parent)), base_(base), bytes_(bytes) {}

    std::uint64_t size() const noexcept override { return bytes_; }

    ReadResult read(std::uint64_t offset, std::span<std::byte> destination) const override {
        if (offset > bytes_ || destination.size() > bytes_ - offset)
            return {Status::invalid_range, 0};
        if (destination.empty()) return {Status::ok, 0};
        // Mount admission proves base_ + bytes_ <= parent size, without wrap.
        return parent_->read(base_ + offset, destination);
    }
private:
    std::shared_ptr<const ByteView> parent_;
    const std::uint64_t base_, bytes_;
};
} // namespace

ViewResult bounded_view(std::shared_ptr<const ByteView> parent, std::uint64_t base,
                        std::uint64_t bytes) noexcept {
    if (!parent) return {Status::invalid_view, {}};
    const auto size = parent->size();
    if (base > size || bytes > size - base) return {Status::invalid_range, {}};
    try {
        return {Status::ok, std::make_shared<const BoundedView>(std::move(parent), base, bytes)};
    } catch (const std::bad_alloc&) {
        return {Status::no_memory, {}};
    }
}

} // namespace reo::native::resources
