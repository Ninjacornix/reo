#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <span>
namespace reo::native::gameplay_scenario {
enum class DescriptorWorkspaceStatus {completed,invalid_asset,exhausted};
// The semantic descriptor-load half of the actual startup-cleared allocation.
// Offsets below are retained asset offsets, never CPU or global RAM addresses.
// Ordinary loading preserves the tail of the prior asset and consumed frames.
class CutsceneDescriptorWorkspace final {
public:
    static constexpr std::size_t capacity=256u*1024u,movie_clear_bytes=96u*1024u;
    //1BAEC0 clears the enclosing startup allocation before this descriptor
    // domain is used. No generic unknown heap state is assumed to be zero.
    CutsceneDescriptorWorkspace()noexcept=default;
    CutsceneDescriptorWorkspace(const CutsceneDescriptorWorkspace&)=delete;
    CutsceneDescriptorWorkspace& operator=(const CutsceneDescriptorWorkspace&)=delete;
    DescriptorWorkspaceStatus load(std::span<const std::byte>)noexcept;
    DescriptorWorkspaceStatus clear_movie_prefix()noexcept;
    // Exact typed event-consumption write: only the frame halfword changes.
    bool consume_frame(std::size_t record_offset,std::uint16_t stride)noexcept;
    std::span<const std::byte> loaded()const noexcept{return std::span(bytes_).first(loaded_bytes_);}
    std::optional<std::span<const std::byte,40>> record40(std::size_t asset_offset)const noexcept;
    std::uint64_t generation()const noexcept{return generation_;}
private:
    std::array<std::byte,capacity> bytes_{};
    std::size_t loaded_bytes_{};
    std::uint64_t generation_{1};
};
} // namespace reo::native::gameplay_scenario
