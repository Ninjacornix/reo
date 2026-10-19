// SPDX-License-Identifier: GPL-3.0-only
#pragma once

#include <cstddef>
#include <cstdint>
#include <functional>
#include <mutex>
#include <string>
#include <vector>

namespace reo_network {

struct NetcnfHostProfile {
    bool available = false;
    std::string address;
    std::string netmask;
    std::string gateway;
    std::string dns1;
    std::string dns2;
};

// NETCNFIF 0x80001101: read-only virtual host configuration, not authentication.
class NetcnfProfileService {
  public:
    using GuestWrite = std::function<bool(uint32_t, const uint8_t*, size_t)>;

    explicit NetcnfProfileService(NetcnfHostProfile profile);
    bool available() const;
    std::vector<uint8_t> call(uint32_t operation, const std::vector<uint8_t>& request,
                              size_t replySize, const GuestWrite& write);

  private:
    NetcnfHostProfile profile_;
    std::mutex mutex_;
    bool registered_ = false;
    std::vector<uint8_t> workspace_;
};

} // namespace reo_network
