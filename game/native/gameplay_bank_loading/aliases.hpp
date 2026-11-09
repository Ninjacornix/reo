#pragma once
#include <array>
#include <optional>
#include <span>
#include <string>
#include <string_view>
namespace reo::native::gameplay_bank_loading {
std::span<const std::string_view,422> sound_aliases()noexcept;
// Complete bounded ASCII1AB050 normalization/first-match lookup. Paths need
// not match AFS display names; aliases identify original member ordinals.
std::optional<std::string> normalize_sound_name(std::string_view);
std::optional<unsigned> sound_member(std::string_view);
}
