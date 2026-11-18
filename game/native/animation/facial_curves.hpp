#pragma once
#include "facial_pose_math.hpp"
#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <span>
#include <vector>
namespace reo::native::animation {
struct FacialKey {std::int32_t frame{};float value{};};
class FacialCurves final {
public:
    static std::shared_ptr<const FacialCurves> import(std::span<const std::byte>);
    std::span<const FacialKey> channel(std::size_t index)const{return channels_.at(index);}
private:
    std::array<std::vector<FacialKey>,5> channels_;
};
struct FacialCursor {
    bool active{true};
    std::uint32_t frame{};
    std::array<std::size_t,5> positions{};
};
struct FacialCurveStep {
    std::optional<FacialWeights> weights;
    //67C6D0 retires the instance and returns the WHOLE eight-instance pass.
    // No matrices or later instances are visited after this becomes true.
    bool stop_batch{};
};
// Source67C6D0's five curves, residual, cursor and terminal policy. The local
// cursor is the actual instance+1C and advances by2 per call; it is independent
// of the borrowed cinematic frame. Unsupported input throws at the boundary.
FacialCurveStep advance_facial_curves(FacialCursor&,const FacialCurves&);
} // namespace reo::native::animation
