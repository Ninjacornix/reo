#include "native_movie_owner.h"
#include "parent_first_entry.h"
#include <exception>

// Harness-only bindings. This executable has no guest, movie service or admitted
// resident owner. A request to activate one is a failed harness precondition.
// Never link this translation unit into the game runtime.
namespace reo_parent_natural {
void setActualFirstEntryEnrollmentRequested(bool enabled) noexcept {
    if (enabled)
        std::terminate();
}
} // namespace reo_parent_natural
namespace reo_movie_owner {
void retireActualOwner(const std::shared_ptr<Target>& owner) noexcept {
    if (owner)
        std::terminate();
}
} // namespace reo_movie_owner
