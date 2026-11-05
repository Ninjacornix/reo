#pragma once

#include "byte_view.hpp"

namespace reo::assets { struct VirtualFile; }

namespace reo::native::resources {

// Freezes validated segment metadata and memory bytes. Source files are privately
// reopened using the existing Source implementation; their bytes must remain
// externally immutable throughout the view's lifetime. No content snapshot/hash
// or independently implemented AFS reader is implied.
class VirtualFileView final : public ByteView {
public:
    [[nodiscard]] static ViewResult create(const reo::assets::VirtualFile& file) noexcept;
    ~VirtualFileView() override;
    [[nodiscard]] std::uint64_t size() const noexcept override;
    [[nodiscard]] ReadResult read(std::uint64_t offset,
                                std::span<std::byte> destination) const override;
private:
    struct Impl;
    explicit VirtualFileView(std::unique_ptr<Impl> impl) noexcept;
    std::unique_ptr<Impl> impl_;
};

} // namespace reo::native::resources
