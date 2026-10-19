// SPDX-License-Identifier: GPL-3.0-only
#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

// Host transport for the verified 0x01270110 SNIOPINT RPC ABI.
// The caller controls opt-in and guest memory ownership; this class owns sockets only.
class SnapIopTransport {
  public:
    SnapIopTransport();
    ~SnapIopTransport();
    SnapIopTransport(const SnapIopTransport&) = delete;
    SnapIopTransport& operator=(const SnapIopTransport&) = delete;
    std::vector<uint8_t> call(uint32_t op, const std::vector<uint8_t>& request, size_t replySize);
    void reset();

  private:
    struct Impl;
    std::unique_ptr<Impl> impl_;
};
