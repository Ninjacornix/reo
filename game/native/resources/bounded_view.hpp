#pragma once

#include "byte_view.hpp"

namespace reo::native::resources {

// Retains the immutable parent without copying bytes. Offsets are relative to
// the admitted subrange; direct reads retain ByteView's partial-failure policy.
// Use ResourceSession::read_exact when caller output must be transactional.
[[nodiscard]] ViewResult bounded_view(std::shared_ptr<const ByteView> parent,
                                      std::uint64_t base, std::uint64_t bytes) noexcept;

} // namespace reo::native::resources
