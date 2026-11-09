#pragma once
// Private selection policy shared by native spatial scans and the independent
// original-scanner comparison fixture. Unordered distances keep the first hit.
namespace reo::native::gameplay_collision::spatial::detail {
inline bool replaces(bool present, float candidate, float selected) noexcept {
    return !present || candidate < selected;
}
} // namespace reo::native::gameplay_collision::spatial::detail
