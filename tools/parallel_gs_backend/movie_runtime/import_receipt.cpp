#include "import_receipt.h"
namespace reo_movie_import {
thread_local Receipt* activeReceipt = nullptr;
thread_local Receipt lastReceipt{};
uint32_t provider_version() noexcept {
    return 1;
}
} // namespace reo_movie_import
