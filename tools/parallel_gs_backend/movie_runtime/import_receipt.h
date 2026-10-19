#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <cstdint>
#include <exception>
#include <stdexcept>

namespace reo_movie_import {
struct Receipt {
    uintptr_t handle = 0;
    bool providerCloseCalled = false, providerCloseSucceeded = false;
    bool callerCloseCalled = false, callerCloseSucceeded = false;
};
// Definitions exist ONLY in the one source-preserving allocator provider.
// An old provider archive cannot satisfy this explicit versioned contract.
extern thread_local Receipt* activeReceipt;
extern thread_local Receipt lastReceipt;
uint32_t provider_version() noexcept;
inline void provider_closed(uintptr_t handle, bool succeeded) noexcept {
    auto* receipt = activeReceipt;
    if (receipt && receipt->handle == handle) {
        receipt->providerCloseCalled = true;
        receipt->providerCloseSucceeded = succeeded;
    }
}
class HandleTransaction {
    Receipt receipt_{};
    Receipt* previous_ = nullptr;

  public:
    explicit HandleTransaction(HANDLE handle) : previous_(activeReceipt) {
        if (!handle || provider_version() != 1)
            throw std::runtime_error("Missing exact pinned import receipt provider");
        receipt_.handle = reinterpret_cast<uintptr_t>(handle);
        activeReceipt = &receipt_;
    }
    HandleTransaction(const HandleTransaction&) = delete;
    ~HandleTransaction() noexcept {
        if (!receipt_.providerCloseCalled) {
            receipt_.callerCloseCalled = true;
            receipt_.callerCloseSucceeded =
                CloseHandle(reinterpret_cast<HANDLE>(receipt_.handle)) != FALSE;
        }
        lastReceipt = receipt_;
        activeReceipt = previous_;
        // Continuing after unaccounted/failed close would lose real ownership.
        if ((receipt_.providerCloseCalled && !receipt_.providerCloseSucceeded) ||
            (receipt_.callerCloseCalled && !receipt_.callerCloseSucceeded))
            std::terminate();
    }
};
} // namespace reo_movie_import
